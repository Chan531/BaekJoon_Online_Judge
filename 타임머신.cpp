#include <iostream>
#include <vector>
#define N 1e9

using namespace std;

struct node {
	int start, end;
	long long cost;
};

int n, m;
long long route[501];
node bus[6000];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		bus[i] = { a, b, c };
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
		route[i] = N;

	// 1 -> 1을 0으로 설정
	route[1] = 0;

	// 총 n - 1번 실행 (최단거리를 이루는 간선의 최대 개수가 n - 1개라서)
	// https://www.acmicpc.net/board/view/74846 참고
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int start = bus[j].start;
			int end = bus[j].end;
			int cost = bus[j].cost;;

			// 출발지에 가본 적 없으면 pass
			if (route[start] == N)
				continue;

			if (route[end] > route[start] + cost)
				route[end] = route[start] + cost;
		}
	}

	// 한 번 더 실행했는데 갱신이 된다면 음수 사이클이 존재한다는 뜻
	for (int i = 0; i < m; i++)
	{
		int start = bus[i].start;
		int end = bus[i].end;
		int cost = bus[i].cost;;

		if (route[start] == N)
			continue;

		if (route[end] > route[start] + cost)
		{
			cout << -1;
			return;
		}
	}

	for (int i = 2; i <= n; i++)
		route[i] == N ? cout << -1 << '\n' : cout << route[i] << '\n';
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