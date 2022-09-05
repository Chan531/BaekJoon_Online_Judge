#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, p, flow[401][401], capacity[401][401], visited[401], ans;
vector<int> path[401];

void input()
{
	cin >> n >> p;

	while (p--)
	{
		int a, b;

		cin >> a >> b;

		capacity[a][b]++;
		path[a].push_back(b);
		path[b].push_back(a);
	}
}

void solution()
{
	while (1)
	{
		queue<int> q;
		q.push(1);
		memset(visited, -1, sizeof(visited));
		visited[1] = 0;

		while (!q.empty())
		{
			int pos = q.front();
			q.pop();

			if (pos == 2)
				break;

			for (int i = 0; i < path[pos].size(); i++)
			{
				int npos = path[pos][i];

				if (capacity[pos][npos] - flow[pos][npos] > 0 && visited[npos] == -1)
				{
					visited[npos] = pos;
					q.push(npos);
				}
			}
		}

		if (visited[2] == -1)
			break;

		for (int i = 2; i != 1; i = visited[i])
		{
			flow[visited[i]][i]++;
			flow[i][visited[i]]--;
		}

		ans++;
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