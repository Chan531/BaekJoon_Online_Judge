#include <iostream>

using namespace std;

int a, b, ans;

void input()
{
	cin >> a >> b;
}

void solution()
{
	if (a % 2 == 0)
	{
		ans++;
		a++;
	}

	if (b % 2)
	{
		ans++;
		b--;
	}

	ans += (b - a + 1) / 2;
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