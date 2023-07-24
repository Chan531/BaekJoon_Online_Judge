#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;
double a, b, val;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		cin >> a >> b;

		if (val < a / b)
		{
			val = a / b;
			ans = b;
		}

		else if (val == a / b && ans > b)
			ans = b;
	}

	cout << ans << '\n';
	val = 0;
	ans = 0;
}

void solve()
{
	int tc;
	cin >> tc;

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