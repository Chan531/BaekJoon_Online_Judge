#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n + 1);
	for (int i = 2; i <= n; i++)
	{
		if (v[i] == 0)
		{
			k--;
			if (k == 0)
			{
				cout << i;
				return 0;
			}
			for (int j = i * 2; j <= n; j += i)
			{
				if (v[j] == 0)
				{
					v[j] = 1;
					k--;
				}
				if (k == 0)
				{
					cout << j;
					return 0;
				}
			}
		}
	}
	return 0;
}