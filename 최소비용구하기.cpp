#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	int n, m, start, end, cost, cp;
	vector<pair<int, int>> bus[1001];
	priority_queue<pair<int, int>> pq;
	cin >> n >> m;
	vector<int> tfee(n + 1, 1e9);

	for (int i = 0; i < m; i++)
	{
		cin >> start >> end >> cost;
		bus[start].push_back(make_pair(end, cost));
	}
	cin >> start >> end;

	tfee[start] = 0;
	pq.push(make_pair(0, start));                            // 비용과 시작점 삽입

	while (!pq.empty())
	{
		cost = -pq.top().first;
		cp = pq.top().second;
		pq.pop();

		if (cost > tfee[cp])
			continue;

		for (int i = 0; i < bus[cp].size(); i++)
		{
			if (cost + bus[cp][i].second < tfee[bus[cp][i].first])
			{
				tfee[bus[cp][i].first] = cost + bus[cp][i].second;
				pq.push(make_pair(-tfee[bus[cp][i].first], bus[cp][i].first));
			}
		}
	}
	cout << tfee[end];
	return 0;
}