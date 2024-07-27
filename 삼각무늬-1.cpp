#include <iostream>

using namespace std;

int a, b, val, ans;

void input()
{
	cin >> a >> b;
}

void solution()
{
	ans = 0;
	val = 1;

	for (int i = 0; i < a / b; i++)
	{
		ans += val;
		val += 2;
	}

	cout << ans << '\n';
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