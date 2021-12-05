#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int zero = 0, one = 0, two = 0, three = 0, four = 0, n, m, car;
	vector<vector<char>> map(50, vector<char> (50));
	vector<vector<int>> dir = { {0,0}, {0,1},{1,1},{1,0} };
	string line;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> line;
		for (int j = 0; j < m; j++)
			map[i][j] = line[j];
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			car = 0;
			for (int k = 0; k < 4; k++)
			{
				int nx = j + dir[k][1];
				int ny = i + dir[k][0];
				if (map[ny][nx] == '#')
				{
					car = -1;
					break;
				}
				else if (map[ny][nx] == 'X')
					car++;
			}
			if (car == 0)
				zero++;
			else if (car == 1)
				one++;
			else if (car == 2)
				two++;
			else if (car == 3)
				three++;
			else if (car == 4)
				four++;
		}
	}
	cout << zero << '\n' << one << '\n' << two << '\n' << three << '\n' << four;
	return 0;
}