#include <iostream>
#include <algorithm>

using namespace std;

int n, ans, val = 1e9 + 1;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int k;
		cin >> k;

		if (k == -1)
		{
			ans += val;
			val = 1e9 + 1;
			continue;
		}

		val = min(val, k);
	}

	cout << ans + val;
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