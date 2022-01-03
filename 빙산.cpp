#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int n, m, num, x, y, nx, ny, year = -1, st;
vector<vector<int>> map(300, vector<int>(300)), dir = { {-1,0},{0,1},{1,0},{0,-1} }, checkmap(300, vector<int>(300)), currentice(300, vector<int>(300));

void checkiceberg(int y, int x)
{
	if (checkmap[y][x] == 1)
		return;

	checkmap[y][x] = 1;

	for (int k = 0; k < 4; k++)
	{
		ny = y + dir[k][0];
		nx = x + dir[k][1];

		if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx])
			checkiceberg(ny, nx);
	}
}

void resizecheckmap()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			checkmap[i][j] = 0;
	}
}

void checkicebergcnt()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] && !checkmap[i][j])
			{
				if (st == 0)
				{
					checkiceberg(i, j);
					st++;
				}
				else
				{
					cout << year + 1;
					exit(0);
				}
			}
		}
	}
	resizecheckmap();
}

int main(void)
{
	cin >> n >> m;
	queue<tuple<int, int, int >> iceberg;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> num;
			map[i][j] = num;
			if (num > 0)
			{
				iceberg.push({ i,j,0 });
				currentice[i][j] = 1;
			}
		}
	}
	checkicebergcnt();
	while (!iceberg.empty())
	{
		st = 0;
		y = get<0>(iceberg.front());
		x = get<1>(iceberg.front());
		year = get<2>(iceberg.front());
		iceberg.pop();

		for (int i = 0; i < 4; i++)
		{
			ny = y + dir[i][0];
			nx = x + dir[i][1];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && !currentice[ny][nx])
			{
				if (map[y][x])
					map[y][x]--;
			}
		}
		if (map[y][x])
			iceberg.push({ y,x,year + 1 });

		if ((!iceberg.empty() && year < get<2>(iceberg.front())) || iceberg.empty())
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (!map[i][j] && currentice[i][j])
						currentice[i][j] = 0;
				}
			}
			checkicebergcnt();
		}
	}
	cout << 0;
	return 0;
}