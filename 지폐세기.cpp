#include <iostream>

using namespace std;

int n, ans;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int a, b;
		cin >> a >> b;

		if (a == 136)
			ans += 1000;

		else if (a == 142)
			ans += 5000;

		else if (a == 148)
			ans += 10000;

		else
			ans += 50000;
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