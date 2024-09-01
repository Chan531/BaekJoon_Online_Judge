#include <iostream>
#include <algorithm>

using namespace std;

int n, s, ans;

void input()
{
	cin >> n >> s;
}

int check(int a)
{
	if (a * s % 1000)
		return a * s / 1000 + 1;
	return a * s / 1000;
}

void solution()
{
	while (n--)
	{
		int a;
		cin >> a;

		ans = max(ans, check(a));
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