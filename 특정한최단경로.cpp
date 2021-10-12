#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> rail[801];
vector<vector<int>> v(801, vector<int>(801, 200000001));
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void finddes(int n)
{
	v[n][n] = 0;
	pq.push({ 0, n });
	while (!pq.empty())
	{
		int point = pq.top().second;
		int dis = pq.top().first;
		pq.pop();

		if (dis > v[n][point])
			continue;

		for (int j = 0; j < rail[point].size(); j++)
		{
			int npoint = rail[point][j].first;
			int ndis = rail[point][j].second + dis;
			if (ndis < v[n][npoint])
			{
				v[n][npoint] = ndis;
				pq.push({ ndis,npoint });
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, e, start, end, len, v1, v2, answer;
	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		cin >> start >> end >> len;
		rail[start].push_back({ end, len });
		rail[end].push_back({ start,len });
	}
	cin >> v1 >> v2;
	for (int i = 1; i <= n; i++)
		if (i == 1 || i == v1 || i == v2)
			finddes(i);

	answer = min(v[1][v1] + v[v1][v2] + v[v2][n], v[1][v2] + v[v2][v1] + v[v1][n]);
	if (answer >= 200000001)
		cout << -1;
	else
		cout << answer;
	return 0;
}