#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, ma = 0;
	string s;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int> (m));
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			v[i][j] = s[j] - '0';
			if (v[i][j])
				ma = 1;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			if (v[i][j])
			{
				if (v[i][j] <= v[i][j + 1] && v[i][j] <= v[i + 1][j] && v[i + 1][j + 1])
				{
					v[i + 1][j + 1] = v[i][j] + 1;
					if (ma < v[i + 1][j + 1])
						ma = v[i + 1][j + 1];
				}
				else if (v[i][j] > v[i][j + 1] || v[i][j] > v[i + 1][j])
				{
					if (v[i + 1][j + 1] && v[i][j + 1] && v[i + 1][j])
						v[i + 1][j + 1] = min({ v[i][j], v[i + 1][j], v[i][j + 1] }) + 1;
					if (ma < v[i + 1][j + 1])
						ma = v[i + 1][j + 1];
				}
			}
		}
	}
	cout << ma * ma;
	return 0;
}