#include <iostream>

using namespace std;

int q, n, m;

void input()
{
	cin >> q;
}

void solution()
{
	while (q--)
	{
		cin >> n;

		while (n % 2 == 0)
			n /= 2;

		if (n == 1)
			cout << "1\n";

		else
			cout << "0\n";
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

	solve();
	return 0;
}