#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m, num;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> num;
			v[i][j] = num;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (!i)
		{
			for (int j = 1; j < m; j++)
				v[i][j] += v[i][j - 1];
			continue;
		}
		for (int j = 0; j < m; j++)
		{
			if (!j)
			{
				v[i][j] += v[i - 1][j];
				continue;
			}
			v[i][j] += max(v[i][j - 1], v[i - 1][j]);
		}
	}
	cout << v[n - 1][m - 1];
	return 0;
}