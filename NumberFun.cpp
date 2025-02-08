#include <iostream>

using namespace std;

int n, a, b, c;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		cin >> a >> b >> c;

		if (a + b == c || a - b == c || b - a == c || a * b == c || (a / b == c && a % b == 0) || (b / a == c && b % a == 0))
			cout << "Possible\n";

		else cout << "Impossible\n";
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