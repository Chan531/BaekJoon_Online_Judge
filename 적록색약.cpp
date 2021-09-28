#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dir = { {-1,0},{0,1},{1,0},{0,-1} };

int nrgb(int x, int y, char c, vector<vector<char>>& v, vector<vector<int>>& nvisited)
{
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dir[k][1];
		int ny = y + dir[k][0];

		if (nx >= 0 && nx < v[0].size() && ny >= 0 && ny < v.size() && !nvisited[ny][nx] && v[ny][nx] == c)
		{
			nvisited[ny][nx] = 1;
			nrgb(nx, ny, c, v, nvisited);
		}
	}

	return 0;
}

int rgb(int x, int y, char c, vector<vector<char>>& v, vector<vector<int>>& visited)
{
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dir[k][1];
		int ny = y + dir[k][0];

		if (nx >= 0 && nx < v[0].size() && ny >= 0 && ny < v.size() && !visited[ny][nx])
		{
			if ((c == 'R' || c == 'G') && (v[ny][nx] == 'R' || v[ny][nx] == 'G'))
			{
				visited[ny][nx] = 1;
				rgb(nx, ny, c, v, visited);
			}

			if (c == 'B' && v[ny][nx] == 'B') 
			{
				visited[ny][nx] = 1;
				rgb(nx, ny, c, v, visited);
			}
		}
	}

	return 0;
}

int main(void)
{
	int n, cnt = 0, ncnt = 0;
	string s;
	cin >> n;
	vector<vector<char>> v(n, vector<char> (n));
	vector<vector<int>> visited(n, vector<int> (n)), nvisited(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
			v[i][j] = s[j];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!nvisited[i][j])
			{
				nvisited[i][j] = 1;
				nrgb(j, i, v[i][j], v, nvisited);
				ncnt++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				visited[i][j] = 1;
				rgb(j, i, v[i][j], v, visited);
				cnt++;
			}
		}
	}
	cout << ncnt << ' ' << cnt;
}