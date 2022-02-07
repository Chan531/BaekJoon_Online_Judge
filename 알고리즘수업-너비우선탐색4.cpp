#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, r, u, v, cnt = 1;
long long ans = 0;
int visited[100001];
vector<int> line[100001];
vector<long long> t(100001), d(100001, -1);

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
		t[num] = cnt++;
		d[num] = depth;

		sort(line[num].begin(), line[num].end());

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
		ans += t[i] * d[i];
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