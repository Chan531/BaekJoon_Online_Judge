#include <iostream>
#include <vector>

using namespace std;

int a, b, c, d;

void solution()
{
	cout << c - b << ' ' << d - a << '\n';
}

void solve()
{
	while (1)
	{
		cin >> a >> b >> c >> d;

		if (a == 0 && b == 0 && c == 0 && d == 0)
			break;

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