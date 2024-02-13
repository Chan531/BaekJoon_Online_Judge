#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	cout << n << ' ';

	while (n >= 10)
	{
		int temp = n;
		int ans = 1;

		while (temp != 0)
		{
			ans *= (temp % 10);
			temp /= 10;
		}

		cout << ans << ' ';
		n = ans;
	}

	cout << '\n';
}

void solve()
{
	while (1)
	{
		input();

		if (!n)
			break;

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