#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m, maxcnt;
	vector<int> sum(41);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sum[i + j]++;
		}
	}
	maxcnt = *max_element(sum.begin(), sum.end());
	for (int i = 1; i <= n + m; i++)
	{
		if (sum[i] == maxcnt)
			cout << i << '\n';
	}
	return 0;
}