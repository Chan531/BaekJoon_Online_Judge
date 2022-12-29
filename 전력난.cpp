// 시간복잡도 : 우선순위 큐 삽입 및 정렬 O(n * log n), 최적화된 분리집합 O(log m)을 m번 반복 -> O(m * log m)
// 공간복잡도 : 200000 * 4byte (root[N]) + 최대 200000개의 정보를 담는 node형 우선순위 큐 200000 * 12byte -> 320kb
// 어려웠던 부분 : 최소 스패닝 트리를 통해 풀이 할 수 있다는 걸 한 번에 캐치하지 못했고(약 10분 소비) 캐치한 다음 우선순위 큐의 비교함수를 설정하는 과정에서 또다시 구글링 함 또한 우선순위 큐와 분리집합의 시간복잡도를 혼자 생각할 생각을 안하고 바로 구글링해버림 다음에는 그러지 않도록.

#include <iostream>
#include <queue>
#define N 200000 // 집의 수 m의 최댓값 (0 ≤ x, y < m)

using namespace std;

struct node {
	int x, y, dis;
	// 집 번호 x, y와 그 사이의 거리
};

int n, m, root[N];
// 길의 수, 집의 수

void input()
{
	cin >> m >> n;
}

// 우선순위 큐 오름차순 정리
struct cmp
{
	bool operator()(node a, node b)
	{
		return a.dis > b.dis;
	}
};

// 분리 집합 처리
int find(int a)
{
	if (a == root[a])
		return a;

	return root[a] = find(root[a]);
}

void solution()
{
	// 최소 스패닝 트리 활용을 위한 오름차순 우선순위 큐
	priority_queue<node, vector<node>, cmp> pq;
	int ans = 0;

	while (n--)
	{
		// x번 집과 y번 집 사이에 양방향 도로가 있으며 그 거리가 z미터
		int x, y, z;
		cin >> x >> y >> z;

		// 절약한 값을 알기 위해 모든 거리 더해주기
		ans += z;
		pq.push({ x,y,z });
	}

	// 분리 집합 루트 초기 설정
	for (int i = 0; i < m; i++)
		root[i] = i;

	while (!pq.empty())
	{
		int x = pq.top().x;
		int y = pq.top().y;
		int dis = pq.top().dis;
		pq.pop();

		// 소속된 집합 찾아주기
		int xroot = find(x);
		int yroot = find(y);

		// 만약 같다면 사이클 발생
		if (xroot == yroot)
			continue;

		// 이 거리는 전구를 켜야하므로 절약한 거리 x
		ans -= dis;

		// 더 작은 값을 집합의 대표값으로 설정
		if (xroot < yroot)
			root[yroot] = xroot;

		else
			root[xroot] = yroot;
	}

	cout << ans << '\n';
}

void solve()
{
	while (1)
	{
		input();

		// 입력의 끝에서는 첫 줄에 0이 2개 주어진다.
		if (n == 0 && m == 0)
			break;

		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}