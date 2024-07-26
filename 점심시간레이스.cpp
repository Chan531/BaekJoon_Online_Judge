#include <iostream>

using namespace std;

int n, m, k, temp = 1e9, ans;

void input()
{
	cin >> n >> m >> k;
}

void solution()
{
	for (int i = 1; i <= k; i++)
	{
		int a, b;
		cin >> a >> b;

		if (temp > n - b + a - 1)
		{
			temp = n - b + a - 1;
			ans = i;
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