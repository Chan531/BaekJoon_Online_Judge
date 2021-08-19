#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> color;
vector<vector<char>> v;

void recolch(int n, int m)
{
	int col = 0;
	char c = v[n][m];
	for (int h = n; h < n + 8; h++)
	{
		for (int w = m; w < m + 8; w++)
		{
			if ((h - n) % 2 == (w - m) % 2)
			{
				if (v[h][w] != c)
					col++;
			}
			else if ((h - n) % 2 != (w - m) % 2)
			{
				if (v[h][w] == c)
					col++;
			}
		}
	}
	color.push_back(col);

	col = 0;
	if (v[n][m] == 'W')
		c = 'B';
	else
		c = 'W';
	for (int h = n; h < n + 8; h++)
	{
		for (int w = m; w < m + 8; w++)
		{
			if ((h - n) % 2 == (w - m) % 2)
			{
				if (v[h][w] != c)
					col++;
			}
			else if ((h - n) % 2 != (w - m) % 2)
			{
				if (v[h][w] == c)
					col++;
			}
		}
	}
	color.push_back(col);
}

int main(void)
{
	int n, m;
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		vector<char> line;
		cin >> s;
		for (auto k : s)
			line.push_back(k);
		v.push_back(line);
	}
	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			recolch(i, j);
		}
	}
	cout << *min_element(color.begin(), color.end());
	return 0;
}