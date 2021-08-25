#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, k, u, x, w, d, p, di;
	cin >> v >> e >> k;
	vector<pair<int, int>> vec[20001];
	vector<int> visited(v + 1);
	vector<int> dis(v + 1, 1e9);
	priority_queue<pair<int, int>> pq;
	dis[k] = 0;
	pq.push(make_pair(0, k));                                  // �Ÿ� ��� ����

	for (int i = 0; i < e; i++)
	{
		cin >> u >> x >> w;
		vec[u].push_back(make_pair(x, w));                     // ��� �Ÿ� ����
	}

	while(!pq.empty())
	{
		di = -pq.top().first;
		k = pq.top().second;
		visited[k] = 1;
		pq.pop();

		if (dis[k] < di)
			continue;

		for (int j = 0; j < vec[k].size(); j++)
		{
			d = vec[k][j].second;                              // �Ÿ�
			p = vec[k][j].first;                               // ���

			if (d + dis[k] < dis[p])
			{
				dis[p] = d + dis[k];
				pq.push(make_pair(-dis[p], p));
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{	
		if (dis[i] < 2000000)
			cout << dis[i] << '\n';
		else
			cout << "INF\n";
	}
	return 0;
}