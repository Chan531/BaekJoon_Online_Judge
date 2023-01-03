// 시간복잡도 : 우선순위 큐 삽입 및 정렬 O(n * log n)
// 공간복잡도 : 100000 * 8byte (p arr[100000])
// 어려웠던 부분 : 맨 처음 떠올렸던 아이디어가 이분 탐색인데 중간에 풀이를 아예 생각이 안 나서 이분 탐색이 아닌가? 싶었는데 빠져나오지를 못함 우선순위 큐는 아예 생각을 안 해서 알고리즘 분류를 보고도 감을 못 잡음 결국 구글링을 하고 감을 잡음 또한 우선순위 큐 정렬 함수를 또 구글링 함

#include <iostream>
#include <queue>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, ans;
p arr[100000]; // 회의의 시작과 끝을 담는 배열

// 우선순위 큐 오름차순 정렬
struct cmp
{
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
}

void solution()
{
	// 회의 시작 시간 오름차순 정렬
	sort(arr, arr + n);

	priority_queue<int, vector<int>, cmp> pq;

	for (int i = 0; i < n; i++)
	{
		// 이전 회의의 끝 시간이 다음 회의의 시작 시간보다 작다면 이미 끝난 회의이므로 삭제
		while (!pq.empty() && pq.top() <= arr[i].first)
			pq.pop();

		// 회의 끝 시간 삽입
		pq.push(arr[i].second);

		// 지금 이 순간 진행되는 최대 회의 개수가 최대로 필요한 회의실 개수를 뜻한다.
		ans = max(ans, (int)pq.size());
	}

	cout << ans;
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}