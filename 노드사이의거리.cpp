#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define N 1010
#define p pair<int, int>

using namespace std;

int n, m;
vector<p> node[N];
bool visited[N];

void input()
{
	cin >> n >> m;

	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b, c });
		node[b].push_back({ a, c });
	}
}

int bfs(int cur, int tar)
{
	queue<p> q;
	q.push({ cur, 0 });
	visited[cur] = 1;

	while (!q.empty())
	{
		int cur = q.front().first;
		int dis = q.front().second;
		q.pop();

		if (cur == tar)
			return dis;

		for (int i = 0; i < node[cur].size(); i++)
		{
			int next = node[cur][i].first;
			int ndis = dis + node[cur][i].second;

			if (visited[next])
				continue;

			visited[next] = 1;
			q.push({ next, ndis });
		}
	}
}

void solution()
{
	while (m--)
	{
		int a, b;
		cin >> a >> b;

		cout << bfs(a, b) << '\n';
		memset(visited, 0, sizeof(visited));
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

	solve();
	return 0;
}