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
		int a, b, c;
		cin >> a >> b >> c;

		if (a == -1) continue;
		if (a == -1) a = 120;
		if (b == -1) b = 120;
		if (c == -1) c = 120;
		if (a <= b && b <= c) ans++;
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