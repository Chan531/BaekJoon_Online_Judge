#include <iostream>

using namespace std;

int n, m, q;

void input()
{
	cin >> n >> m >> q;
}

void solution()
{
	while (q--)
	{
		int a, b;
		cin >> a >> b;
		if (a == m)
			m = b;
		else if (b == m)
			m = a;
	}
	cout << m;
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