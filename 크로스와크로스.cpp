#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, dp[2020];

void input()
{
	cin >> n;
}

void solution()
{
	dp[1] = dp[2] = dp[3] = 1;

	for (int i = 4; i <= n; i++)
	{
		vector<int> v;
		int val;

		for (int j = 1; j <= (i + 1) / 2; j++)
		{
			if (j > 3)
				val = dp[j - 3] ^ dp[i - j - 2];

			else
				val = dp[i - j - 2];

			v.push_back(val);
		}

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