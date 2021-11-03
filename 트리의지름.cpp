#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> v(10001);
vector<int> visited(10001);
queue<pair<int, int>> q;

int main(void)
{
	int n, a, b, c, max = 0;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back(make_pair(c, b));
		v[b].push_back(make_pair(c, a));
	}
	for (int i = n; i > 1; i--)
	{
		visited[i] = 1;
		if (v[i][0].second > i)
			break;
		q.push(make_pair(v[i][0].first, v[i][0].second));
		while (!q.empty())
		{
			int dis = q.front().first;
			int node = q.front().second;

			q.pop();

			visited[node] = 1;

			if (v[node].size() == 1 && visited[v[node][0].second])
			{
				if (dis > max)
					max = dis;
				continue;
			}

			for (int j = 0; j < v[node].size(); j++)
			{
				int ndis = v[node][j].first + dis;
				int nnode = v[node][j].second;

				if (!visited[nnode])
					q.push(make_pair(ndis, nnode));
			}
		}
		for (int j = 1; j < i; j++)
			visited[j] = 0;
	}
	cout << max;
	return 0;
}