#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, m, r, item[101], testdis[101], ans;
vector<p> path[101];

void input()
{
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
		cin >> item[i];

	while (r--)
	{
		int s, e, dis;
		cin >> s >> e >> dis;

		path[s].push_back({ dis, e });
		path[e].push_back({ dis, s });
	}
}

void setdis(int pos)
{
	for (int i = 1; i <= n; i++)
		testdis[i] = 1e9;

	testdis[pos] = 0;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		priority_queue<p, vector<p>, greater<p>> pq;
		pq.push({ 0, i });
		setdis(i);

		while (!pq.empty())
		{
			int dis = pq.top().first;
			int pos = pq.top().second;
			pq.pop();

			if (dis > m || dis > testdis[pos])
				continue;

			sum += item[pos];

			for (int j = 0; j < path[pos].size(); j++)
			{
				int npos = path[pos][j].second;
				int ndis = dis + path[pos][j].first;

				if (ndis < testdis[npos])
				{
					pq.push({ ndis, npos });
					testdis[npos] = ndis;
				}
			}
		}

		ans = max(ans, sum);
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