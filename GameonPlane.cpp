#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, dp[5050];

void init()
{
	dp[2] = 1;

	for (int i = 3; i <= 5000; i++)
	{
		vector<int> v;

		for (int j = 0; j < i / 2; j++)
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
}

void input()
{
	cin >> n;
}

void solution()
{
	dp[n] ? cout << "First\n" : cout << "Second\n";
}

void solve()
{
	int tc;
	cin >> tc;

	init();

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}