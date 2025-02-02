#include <iostream>
#include <algorithm>

using namespace std;

int ans, sum[1010];
string s;

void input()
{
	cin >> s;
}

void solution()
{
	sum[0] = s[0];

	for (int i = 1; i < s.length(); i++)
		sum[i] = sum[i - 1] + s[i];

	for (int i = 0; i < s.length(); i++)
	{
		for (int j = i + 1; j < s.length(); j += 2)
		{
			if (sum[j] - sum[i] + s[i] == (sum[(i + j) / 2] - sum[i] + s[i]) * 2)
				ans = max(ans, j - i + 1);
		}
	}

	cout << ans;
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