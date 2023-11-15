#include <iostream>

using namespace std;

int n, ans, pa, pb;

void input()
{
	cin >> n >> pa >> pb;
}

void solution()
{
	if (pa == pb && pa != 0)
		ans++;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		if (a == b && a != 0)
			ans++;

		if (pa == a && pa != 0)
			ans++;

		if (pb == b && pb != 0)
			ans++;

		pa = a;
		pb = b;
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