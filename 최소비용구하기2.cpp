#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> buscost(1001, vector<int>(1001, -1)), rail(1001);
vector<int> mincost(1001, 100000001), visited(1001), bpos(1001), order;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void)
{
	int n, m, start, end, cost, pos, ncost, npos;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> start >> end >> cost;
		if (buscost[start][end] == -1 || buscost[start][end] > cost)
			buscost[start][end] = cost;
		rail[start].push_back(end);
	}
	cin >> start >> end;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		cost = pq.top().first;
		pos = pq.top().second;
		pq.pop();

		if (pos == end)
		{
			while (1)
			{
				order.push_back(pos);
				if (pos == start)
					break;
				pos = bpos[pos];
			}
			cout << cost << '\n' << order.size() << '\n';
			for (int i = order.size() - 1; i >= 0; i--)
				cout << order[i] << ' ';
			break;
		}

		if (visited[pos])
			continue;

		visited[pos] = 1;

		for (int i = 0; i < rail[pos].size(); i++)
		{
			npos = rail[pos][i];
			ncost = cost + buscost[pos][npos];
			if (ncost < mincost[npos])
			{
				mincost[npos] = ncost;
				pq.push(make_pair(ncost, npos));
				bpos[npos] = pos;
			}
		}
	}
	return 0;
}