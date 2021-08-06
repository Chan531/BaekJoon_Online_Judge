#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<vector<int>> v;
	vector<int> box;
	int n, m;
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		vector<int> line;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			line.push_back(s[j] - '0');
		}
		v.push_back(line);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)          
		{
			for (int k = m - 1; k > j; k--)
			{
				if (v[i][j] == v[i][k])
				{
					if (i + k - j >= n)
					{
					}
					else if (v[i + k - j][j] == v[i][j])
					{
						if (v[i + k - j][k] == v[i][k])
							box.push_back(pow(k - j + 1, 2));
					}
				}
			}
		}
	}
	if (box.empty())
		cout << 1;
	else
		cout << *max_element(box.begin(), box.end());
	return 0;
}