#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> route(101, vector<int>(101, 10000001));

int n, m, a, b, c;

void input()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> c;
		route[a][b] = min(route[a][b], c);
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		route[i][i] = 0;
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
				route[j][k] = min(route[j][i] + route[i][k], route[j][k]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (route[i][j] == 10000001)
				route[i][j] = 0;
			cout << route[i][j] << ' ';
		}
		cout << '\n';
	}
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	solve();

	return 0;
}

/* 다익스트라로 푼 듯 이건...?
vector<vector<int>> route(101, vector<int>(101, 100000001));
vector<pair<int, int>> connect[101];

int n, m, a, b, c;

void input()
{
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b >> c;
		connect[a].push_back({ c, b });
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		sort(connect[i].begin(), connect[i].end());
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0,i });
		route[i][i] = 0;
		while (!pq.empty())
		{
			int cost = pq.top().first;
			int pos = pq.top().second;
			pq.pop();

			for (int j = 0; j < connect[pos].size(); j++)
			{
				int ncost = connect[pos][j].first + cost;
				int npos = connect[pos][j].second;

				if (route[i][npos] > ncost)
				{
					route[i][npos] = ncost;
					pq.push({ ncost,npos });
				}
			}
		}
		for (int j = 1; j <= n; j++)
			if (route[i][j] == 100000001)
				route[i][j] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << route[i][j] << ' ';
		cout << '\n';
	}
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
}*/