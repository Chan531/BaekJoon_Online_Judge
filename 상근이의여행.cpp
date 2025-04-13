#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n, m, ans;
vector<int> con[1010];
bool visited[1010];

void input()
{
	cin >> n >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		con[a].push_back(b);
		con[b].push_back(a);
	}
}

void bfs()
{
	queue<int> q;
	q.push(1);
	visited[1] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto i : con[cur])
		{
			if (visited[i]) continue;
			ans++;
			visited[i] = 1;
			q.push(i);
		}
	}
}

void solution()
{
	ans = 0;

	bfs();

	cout << ans << '\n';
	for (int i = 1; i <= n; i++) con[i].clear();
	memset(visited, 0, sizeof(visited));
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}