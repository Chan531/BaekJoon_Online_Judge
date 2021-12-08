#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, num, mcnt = 0;
vector<vector<int>> map(500, vector<int>(500)), dp(500, vector<int>(500, 1));
vector<vector<int>> dir = { {-1,0},{0,1},{1,0},{0,-1} };

int checkmax(int x, int y)
{
	if (dp[y][x] != 1)
		return dp[y][x];

	for (int k = 0; k < 4; k++)
	{
		int nx = x + dir[k][1];
		int ny = y + dir[k][0];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[ny][nx] > map[y][x])
			dp[y][x] = max(dp[y][x], checkmax(nx, ny) + 1);
	}
	return dp[y][x];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			map[i][j] = num;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dp[i][j] == 1)
				mcnt = max(checkmax(j, i), mcnt);
		}
	}
	cout << mcnt;
	return 0;
}