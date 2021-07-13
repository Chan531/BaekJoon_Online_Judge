#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> map;
int direction[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };
deque<pair <int, int>> q;
pair<int, int> p;
int ripen = 0;
int day = 0;
int none = 0;

int BFS(int x, int y)
{
	int nx, ny;
	while (!q.empty())
	{
		p = q.front();
		q.pop_front();
		for (int i = 0; i < 4; i++)
		{
			nx = p.second + direction[i][0];
			ny = p.first + direction[i][1];
			if (nx >= 0 && nx < x && ny >= 0 && ny < y && map[ny][nx] == 0)
			{
				q.push_back(make_pair(ny, nx));
				map[ny][nx] = map[p.first][p.second] + 1;
				ripen++;
				if (day < map[ny][nx])
					day = map[ny][nx];
			}
		}
	}
	if (ripen + none == x * y)
		return day - 1;
	else
		return -1;
}

int main(void)
{
	int m, n;
	cin >> m >> n;
	int a = 0;
	for (int i = 0; i < n; i++)
	{
		vector<int> line;
		for (int j = 0; j < m; j++)
		{
			cin >> a;
			line.push_back(a);
			if (a == 1)
			{
				q.push_back(make_pair(i, j));
				ripen++;
			}
			else if (a == -1)
				none++;
		}
		map.push_back(line);
	}
	if (none + ripen == n * m)
		cout << 0;
	else
		cout << BFS(m, n);
}