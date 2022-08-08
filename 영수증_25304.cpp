#include <iostream>

using namespace std;

int x, n, a, b;

void input()
{
	cin >> x >> n;

	while (n--)
	{
		cin >> a >> b;

		x -= a * b;
	}
}

void solution()
{
	if (x == 0)
		cout << "Yes";

	else
		cout << "No";
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