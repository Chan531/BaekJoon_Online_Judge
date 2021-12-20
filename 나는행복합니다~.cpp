#include <iostream>

using namespace std;

int main(void)
{
	int n, m, num, idx = 0;
	cin >> n >> m >> num;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (idx++ == num)
			{
				cout << i << ' ' << j;
				return 0;
			}
		}
	}
	return 0;
}