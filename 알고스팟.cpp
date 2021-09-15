#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m, x, y, aoj, maoj = 10000;
	string s;
	cin >> n >> m;
	vector<vector<int>> v(m, vector<int>(n)), visited(m, vector<int>(n));
	priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

	for (int i = 0; i < m; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
			v[i][j] = s[j] - '0';
	}
	q.push(make_pair(0, make_pair(0, 0)));
	while (!q.empty())
	{
		aoj = q.top().first;
		x = q.top().second.first;
		y = q.top().second.second;
		q.pop();

		if (x < 0 || x > n || y < 0 || y > m)
			continue;

		visited[y][x] = 1;

		if (x == n - 1 && y == m - 1)
		{
			maoj = aoj;
			break;
		}

		if (x - 1 >= 0 && !visited[y][x - 1])
		{
			v[y][x - 1] ? q.push(make_pair(aoj + 1, make_pair(x - 1, y))) : q.push(make_pair(aoj, make_pair(x - 1, y)));
			visited[y][x - 1] = 1;
		}

		if (x + 1 < n && !visited[y][x + 1])
		{
			v[y][x + 1] ? q.push(make_pair(aoj + 1, make_pair(x + 1, y))) : q.push(make_pair(aoj, make_pair(x + 1, y))); 
			visited[y][x + 1] = 1;
		}

		if (y - 1 >= 0 && !visited[y - 1][x])
		{
			v[y - 1][x] ? q.push(make_pair(aoj + 1, make_pair(x, y - 1))) : q.push(make_pair(aoj, make_pair(x, y - 1)));
			visited[y - 1][x] = 1;
		}

		if (y + 1 < m && !visited[y + 1][x])
		{
			v[y + 1][x] ? q.push(make_pair(aoj + 1, make_pair(x, y + 1))) : q.push(make_pair(aoj, make_pair(x, y + 1)));
			visited[y + 1][x] = 1;
		}
	}
	cout << maoj;
	return 0;
}