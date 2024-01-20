#include <iostream>

using namespace std;

int n, pre = 1e9, ans;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int m;
		cin >> m;

		if (m > pre)
		{
			ans += m -= pre;
			continue;
		}

		pre = m;
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