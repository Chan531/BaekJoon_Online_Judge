#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, k, div = 1000000000;
	cin >> n >> k;
	vector<vector<long long>> sumdismental(n + 1, vector<long long>(k + 1, 1));

	for (int i = 2; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
			sumdismental[j][i] = (sumdismental[j - 1][i] + sumdismental[j][i - 1]) % div;
	}
	cout << sumdismental[n][k] % div;
	return 0;
}