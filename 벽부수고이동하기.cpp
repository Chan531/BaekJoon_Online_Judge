#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main(void)
{
	int n, m, x, y, cw, mp = 1000000, p, nx, ny;
	string s;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	vector<vector<int>> visited(n, vector<int>(m));     // 오는 동안 벽을 부순 적이 있으면 2, 없으면 1
	visited[0][0] = 1;
	vector<vector<int>> dir = { { -1,0 }, { 0,1 }, { 1,0 }, { 0, -1 } };
	queue<tuple<int, int, int, int>> q;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
			v[i][j] = s[j] - '0';
	}
	q.push(make_tuple(0, 0, 0, 1));                     // 부신 벽의 수, x, y, 경로
	while (!q.empty())
	{
		cw = get<0>(q.front());
		x = get<1>(q.front());
		y = get<2>(q.front());
		p = get<3>(q.front());
		q.pop();

		if (x > m || x < 0 || y > n || y < 0 || cw > 1)
			continue;

		if (y == n - 1 && x == m - 1)
		{
			if (mp > p)
				mp = p;
		}

		for (int i = 0; i < 4; i++)
		{
			nx = x + dir[i][1];
			ny = y + dir[i][0];

			if (nx < m && nx >= 0 && ny < n && ny >= 0 && !visited[ny][nx])
			{
				if (v[ny][nx] && !cw)
				{
					q.push(make_tuple(cw + 1, nx, ny, p + 1));
					visited[ny][nx] = 2;
				}
				else if (!v[ny][nx])
				{
					q.push(make_tuple(cw, nx, ny, p + 1));
					if (cw)
						visited[ny][nx] = 2;
					else
						visited[ny][nx] = 1;
				}
			}

			else if (nx < m && nx >= 0 && ny < n && ny >= 0 && visited[ny][nx] == 2 && !cw)
			{
				if (!v[ny][nx])
				{
					q.push(make_tuple(cw, nx, ny, p + 1));
					visited[ny][nx] = 1;
				}
			}
		}
	}
	if (mp == 1000000)
		cout << -1;
	else
		cout << mp;
	return 0;
}