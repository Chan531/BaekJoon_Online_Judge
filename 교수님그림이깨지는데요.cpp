#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, k, num;
	cin >> n >> k;
	vector<vector<int>> bitmap(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			bitmap[i][j] = num;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int a = 0; a < k; a++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int b = 0; b < k; b++)
					cout << bitmap[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}