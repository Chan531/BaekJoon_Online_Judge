#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define p pair<int, int>
#define N 55

using namespace std;

int n, cnt[N], mincnt = N;
vector<int> con[N], ans;
bool visited[N];

void input()
{
	cin >> n;

	while (1)
	{
		int a, b;
		cin >> a >> b;

		if (a == -1)
			break;

		con[a].push_back(b);
		con[b].push_back(a);
	}
}

int bfs(int node)
{
	queue<p> q;
	q.push({ node, 0 });
	visited[node] = 1;
	int ret = 0;

	while (!q.empty())
	{
		int cur = q.front().first;
		int dis = q.front().second;
		ret = max(ret, dis);
		q.pop();

		for (int i = 0; i < con[cur].size(); i++)
		{
			if (visited[con[cur][i]])
				continue;

			visited[con[cur][i]] = 1;
			q.push({ con[cur][i], dis + 1 });
		}
	}

	return ret;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		cnt[i] = bfs(i);
		mincnt = min(cnt[i], mincnt);
		memset(visited, 0, sizeof(visited));
	}

	for (int i = 1; i <= n; i++)
		if (cnt[i] == mincnt)
			ans.push_back(i);

	cout << mincnt << ' ' << ans.size() << '\n';

	for (auto i : ans)
		cout << i << ' ';
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