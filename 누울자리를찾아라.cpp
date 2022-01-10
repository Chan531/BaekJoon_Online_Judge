#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, widthcnt = 0, heightcnt = 0, widthst, heightst;
	string line;
	cin >> n;
	vector<vector<char>> map(n, vector<char>(n));
	for (int i = 0; i < n; i++)
	{
		cin >> line;
		for (int j = 0; j < n; j++)
			map[i][j] = line[j];
	}
	for (int i = 0; i < n; i++)
	{
		widthst = 0;
		for (int j = 0; j < n - 1; j++)
		{
			if ((map[i][j] == '.' && map[i][j + 1] == '.') && widthst != 1)
			{
				widthcnt++;
				widthst = 1;
			}
			else if (map[i][j] == 'X')
				widthst = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		heightst = 0;
		for (int j = 0; j < n - 1; j++)
		{
			if ((map[j][i] == '.' && map[j + 1][i] == '.') && heightst != 1)
			{
				heightcnt++;
				heightst = 1;
			}
			else if (map[j][i] == 'X')
				heightst = 0;
		}
	}
	cout << widthcnt << ' ' << heightcnt; 
	return 0;
}