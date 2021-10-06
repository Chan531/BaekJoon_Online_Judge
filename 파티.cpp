#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> r[1001];
vector<vector<int>> v(1001, vector<int> (1001, 1000001));
priority_queue<pair <int, int>> pq;

void checkdis(int i)
{
	v[i][i] = 0;
	pq.push(make_pair(0, i));
	while (!pq.empty())
	{
		int di = pq.top().first * -1;
		int po = pq.top().second;
		pq.pop();

		if (di > v[i][po])
			continue;

		for (int k = 0; k < r[po].size(); k++)
		{
			int p = r[po][k].first;
			int d = di + r[po][k].second;
			if (d < v[i][p])
			{
				v[i][p] = d;
				pq.push(make_pair(d * -1, p));
			}
		}
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, x, start, end, dis, ma = 0;
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		cin >> start >> end >> dis;
		r[start].push_back(make_pair(end, dis));
	}
	for (int i = 1; i <= n; i++)
		checkdis(i);

	for (int i = 1; i <= n; i++)
	{
		if (i == x)
			continue;
		if (ma < v[i][x] + v[x][i])
			ma = v[i][x] + v[x][i];
	}
	cout << ma;
	return 0;
}