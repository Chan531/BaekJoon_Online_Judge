#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int t, m, n, num, count;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		vector<vector<int>> box;
		count = 0;
		cin >> m >> n;
		for (int j = 0; j < m; j++)
		{
			vector<int> line;
			for (int k = 0; k < n; k++)
			{
				cin >> num;
				line.push_back(num);
			}
			box.push_back(line);
		}
		for (int i = m - 2; i >= 0; i--)
		{
			for (int j = 0; j < n; j++)
			{
				if (box[i][j] == 1)
				{
					int a = 1;
					while (i + a != m && box[i + a][j] != 1)
					{
						box[i][j] = 0;
						count++;
						a++;
					}
					if (a != 1)
						box[i + a - 1][j] = 1;
				}
			}
		}
		cout << count << '\n';
	}
	return 0;
}