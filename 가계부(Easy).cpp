#include <iostream>
#define ll long long

using namespace std;

int n, m;
ll arr[10101];

void input()
{
	cin >> n >> m;
}

void solution()
{
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
			arr[b] += c;

		else
		{
			ll ans = 0;

			for (int i = b; i <= c; i++)
				ans += arr[i];

			cout << ans << '\n';
		}
	}
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