#include <iostream>

using namespace std;

int t, n, m;

void input()
{
	cin >> t;
}

void solution()
{
	while (t--)
	{
		cin >> n;

		for (int i = 1; i <= n; i += 2)
			m += i;

		cout << m << '\n';
		m = 0;
	}
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
	cout.tie(NULL);

	solve();
	return 0;
}