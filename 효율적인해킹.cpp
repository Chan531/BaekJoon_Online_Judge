#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, cnt[10001];
bool visited[10001];
vector<int> path[10001];

void input()
{
	cin >> n >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;

		path[b].push_back(a);
	}
}

void solution()
{
	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		q.push(i);
		visited[i] = 1;
		cnt[i]++;

		while (!q.empty())
		{
			int pos = q.front();
			q.pop();

			for (int j = 0; j < path[pos].size(); j++)
			{
				int npos = path[pos][j];

				if (!visited[npos])
				{
					visited[npos] = 1;
					q.push(npos);
					cnt[i]++;
				}
			}
		}

		memset(visited, 0, sizeof(visited));
	}

	int maxcnt = *max_element(cnt, cnt + n + 1);

	for (int i = 1; i <= n; i++)
		if (maxcnt == cnt[i])
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
	cout.tie(NULL);

	solve();
	return 0;
}