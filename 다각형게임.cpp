#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, dp[1010];

void input()
{
	cin >> n;
}

void solution()
{
	dp[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		vector<int> v;
		v.push_back(dp[i - 2]);

		for (int j = 1; j < i / 2; j++)
			v.push_back(dp[j] ^ dp[i - 2 - j]);

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		int idx = 0;

		while (1)
		{
			if (idx >= v.size() || v[idx] != idx)
			{
				dp[i] = idx;
				break;
			}
			idx++;
		}
	}

	dp[n] ? cout << 1 : cout << 2;
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}