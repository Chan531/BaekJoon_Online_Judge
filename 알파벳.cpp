#include <iostream>
#include <vector>

using namespace std;

int n, m, ma = 1;
vector<int> visited(26);
vector<vector<char>> v(20, vector<char>(20));
vector<int> dir[4] = { {-1,0},{0,1},{1,0},{0,-1} };

void dfs(int num, int x, int y)
{
	if (ma < num)
		ma = num;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dir[i][1];
		int ny = y + dir[i][0];

		if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[v[ny][nx] - 'A'])
		{
			visited[v[ny][nx] - 'A'] = 1;
			dfs(num + 1, nx, ny);
			visited[v[ny][nx] - 'A'] = 0;
		}
	}
}

int main(void)
{
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
			v[i][j] = s[j];
	}
	visited[v[0][0] - 'A'] = 1;
	dfs(1, 0, 0);
	cout << ma;
	return 0;
}