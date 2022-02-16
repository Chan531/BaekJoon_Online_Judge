// 덱을 이용한 풀이 -> 우선순위 큐보다 메모리 시간 효율 good

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, l;
vector<int> arr(5000001);

void input()
{
	cin >> n >> l;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void solution()
{
	deque<pair<int, int>> dq;

	for (int i = 1; i <= n; i++)
	{
		while (!dq.empty() && dq.back().first > arr[i])    // 범위 내 답이 될 수 없는 애들 삭제
			dq.pop_back();

		dq.push_back({ arr[i], i });

		while (dq.front().second < i - l + 1)              // 순서가 지난 애들 삭제
			dq.pop_front();

		cout << dq.front().first << ' ';
	}
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


// 우선순위 큐를 이용한 풀이 -> 덱보다 발상이 비교적 간단 but 효율 bad
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, l;
vector<int> arr(5000001);

void input()
{
	cin >> n >> l;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void solution()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 1; i <= n; i++)
	{
		pq.push({ arr[i], i });

		while (pq.top().second < i - l + 1)      // 순서가 지난 애들 삭제
			pq.pop();

		cout << pq.top().first << ' ';
	}
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