#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;
int direction[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };
queue<pair <int, int>> q;
pair<int, int> p;

int BFS(int x, int y)
{
	q.push(make_pair(0, 0));
	int nx, ny;
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			nx = p.first + direction[i][0];
			ny = p.second + direction[i][1];
			if (nx >= 0 && nx < x && ny >= 0 && ny < y && map[ny][nx] == 1)
			{
				q.push(make_pair(nx, ny));
				map[ny][nx] = map[p.second][p.first] + 1;
			}
		}
	}
	return map[y - 1][x - 1];
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		vector<int> line;
		string s = "";
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			line.push_back(s[j] - 48);
		}
		map.push_back(line);
	}
	cout << BFS(m, n);
	return 0;
}