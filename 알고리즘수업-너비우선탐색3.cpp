#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, r, u, v;
int visited[100001];
vector<int> line[100001], ans(100001, -1);

void input()
{
	cin >> n >> m >> r;
	while (m--)
	{
		cin >> u >> v;
		line[u].push_back(v);
		line[v].push_back(u);
	}
}

void solution()
{
	queue<pair<int, int>> q;
	q.push({ r, 0 });
	visited[r] = 1;
	while (!q.empty())
	{
		int num = q.front().first;
		int depth = q.front().second;
		q.pop();
		ans[num] = depth;

		for (int i = 0; i < line[num].size(); i++)
		{
			if (!visited[line[num][i]])
			{
				visited[line[num][i]] = 1;
				q.push({ line[num][i], depth + 1 });
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
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