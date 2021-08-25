#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int t, n, m, sum, max, min;
	cin >> t;
	vector<int> v(466);
	for (int i = 2; i <= 30; i++)
	{
		max = i * (i + 1) / 2;
		min = (i - 1) * i / 2 + 1;
		for (int j = min; j <= max; j++)
		{
			if (j == min || j == max)
				v[j] = 1;
			else
				v[j] = v[j - i] + v[j - i + 1];
		}
	}
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		cout << v[(m + 1) * m / 2 + n + 1] << '\n';
	}
	return 0;
}