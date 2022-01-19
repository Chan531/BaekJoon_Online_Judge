#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int t, n, x, y, pos, npos;

vector<pair<int, int>> xy(102);
vector<int> route[102], visited(102);

void Input()
{
	cin >> n;
	for (int i = 0; i < n + 2; i++)
	{
		cin >> x >> y;
		xy[i] = { x, y };
	}
	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < n + 2; j++)
		{
			if (abs(xy[i].first - xy[j].first) + abs(xy[i].second - xy[j].second) <= 1000)
				route[i].push_back(j);
		}
	}
}

void Solve()
{
	queue<int> q;
	q.push(0);
	visited[0] = 1;
	while (!q.empty())
	{
		pos = q.front();
		q.pop();

		if (pos == n + 1)
		{
			cout << "happy\n";
			return;
		}

		for (int i = 0; i < route[pos].size(); i++)
		{
			npos = route[pos][i];
			if (!visited[npos])
			{
				visited[npos] = 1;
				q.push(npos);
			}
		}
	}
	cout << "sad\n";
}

void Reset()
{
	for (int i = 0; i < n + 2; i++)
	{
		route[i].clear();
		visited[i] = 0;
	}
}

int main(void)
{
	cin >> t;
	while (t--)
	{
		Input();
		Solve();
		Reset();
	}
	return 0;
}