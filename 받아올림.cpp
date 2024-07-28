#include <iostream>

using namespace std;

int ans, up;
long long a, b;

void input()
{
	cin >> a >> b;
}

void solution()
{
	ans = 0;
	up = 0;

	while (a || b)
	{
		if (a % 10 + b % 10 + up >= 10)
		{
			up = 1;
			ans++;
		}

		else
			up = 0;

		a /= 10;
		b /= 10;
	}

	cout << ans << '\n';
}

void solve()
{
	while (1)
	{
		input();
		if (!a && !b) break;
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