#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, m;
	string line;
	cin >> n >> m;
	vector<vector<char>> picture(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		cin >> line;
		for (int j = 0; j < m; j++)
			picture[i][j] = line[j];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (picture[i][j] != '.')
				picture[i][m - j - 1] = picture[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << picture[i][j];
		cout << '\n';
	}
	return 0;
}