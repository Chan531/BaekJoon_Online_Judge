#include <iostream>
#include <vector>

using namespace std;
vector<vector<long long>> pill(31, vector<long long>(61));

long long dp(int one, int half)
{
	if (pill[one][half])
		return pill[one][half];

	if (!half)
		return pill[one - 1][1] = dp(one - 1, 1);

	return pill[one][half] = dp(one - 1, half + 1) + dp(one, half - 1);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	fill(pill[0].begin(), pill[0].end(), 1);
	while (1)
	{
		cin >> num;
		if (!num)
			break;
		cout << dp(num - 1, 1) << '\n';
	}
	return 0;
}