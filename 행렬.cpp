#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> matrix(50, vector<int>(50)), nmatrix(50, vector<int>(50)), change(50, vector<int>(50));

void changematrix(int y, int x)
{
	for (int a = y; a < y + 3; a++)
	{
		for (int b = x; b < x + 3; b++)
		{
			if (change[a][b])
				change[a][b] = 0;
			else
				change[a][b] = 1;
		}
	}
}

int main(void)
{
	int n, m, cnt = 0;
	string line;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> line;
		for (int j = 0; j < m; j++)
			matrix[i][j] = line[j] - '0';
	}
	for (int i = 0; i < n; i++)
	{
		cin >> line;
		for (int j = 0; j < m; j++)
		{
			nmatrix[i][j] = line[j] - '0';
			if (matrix[i][j] == nmatrix[i][j])
				change[i][j] = 1;
		}
	}
	if (n < 3 || m < 3)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!change[i][j])
				{
					cout << -1;
					return 0;
				}
			}
		}
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (!change[i][j])
			{
				changematrix(i, j);
				cnt++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!change[i][j])
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << cnt;
	return 0;
}