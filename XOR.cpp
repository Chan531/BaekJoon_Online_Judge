#include <iostream>

using namespace std;

int a, b;

void input()
{
	cin >> a >> b;
}

int f(int n)
{
	if (n % 4 == 0)
		return n;

	else if (n % 4 == 1)
		return 1;

	else if (n % 4 == 2)
		return n + 1;

	else
		return 0;
}

void solution()
{
	int ans = f(b) ^ f(a - 1);
	cout << ans << '\n';
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}