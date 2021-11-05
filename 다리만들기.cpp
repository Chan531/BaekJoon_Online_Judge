#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> v(100, vector<int> (100)), visited(100, vector<int>(100));
vector<vector<int>> dir = { {-1,0},{0,1},{1,0},{0,-1} };
int mi = 200;

void setarea(int x, int y, int col, int n)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		v[y][x] = col;

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dir[k][1];
			int ny = y + dir[k][0];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx] && v[ny][nx] == 1)
			{
				visited[ny][nx] = 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

void bridge(int x, int y, int col, int n)
{
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(0, make_pair(x, y)));
	while (!q.empty())
	{
		int x = q.front().second.first;
		int y = q.front().second.second;
		int cnt = q.front().first;

		q.pop();

		if (cnt >= mi)
			continue;

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dir[k][1];
			int ny = y + dir[k][0];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[ny][nx])
			{
				visited[ny][nx] = 1;
				if (!v[ny][nx])
					q.push(make_pair(cnt + 1, make_pair(nx, ny)));
				else if (v[ny][nx] != col)
				{
					if (mi > cnt)
						mi = cnt;
				}
			}
		}
	}
}

void reset(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			visited[i][j] = 0;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num, col = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			v[i][j] = num;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] == 1 && !visited[i][j])
			{
				visited[i][j] = 1;
				setarea(j, i, col, n);
				col++;
			}
		}
	}
	reset(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j])
			{
				visited[i][j] = 1;
				bridge(j, i, v[i][j], n);
			}
			reset(n);
		}
	}
	cout << mi;
	return 0;
}