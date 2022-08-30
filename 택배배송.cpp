#include <iostream>
#include <vector>
#include <queue>
#define p pair<int, int>

using namespace std;

int n, m, cost[50001];
vector<p> path[50001];

void input()
{
	cin >> n >> m;

	while (m--)
	{
		int a, b, cost;

		cin >> a >> b >> cost;

		path[a].push_back({ b, cost });
		path[b].push_back({ a, cost });
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
		cost[i] = 1e9;

	priority_queue<p, vector<p>, greater<p>> pq;
	pq.push({ 0, 1 });
	cost[1] = 0;

	while (!pq.empty())
	{
		int pos = pq.top().second;
		int charge = pq.top().first;
		pq.pop();

		if (cost[pos] < charge)
			continue;

		for (int i = 0; i < path[pos].size(); i++)
		{
			int npos = path[pos][i].first;
			int ncharge = charge + path[pos][i].second;

			if (cost[npos] > ncharge)
			{
				cost[npos] = ncharge;
				pq.push({ ncharge, npos });
			}
		}
	}

	cout << cost[n];
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