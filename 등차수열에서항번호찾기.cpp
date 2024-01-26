#include <iostream>

using namespace std;

int a, d, k;

void input()
{
	cin >> a >> d >> k;
}

void solution()
{
	if (a == k)
	{
		cout << 1;
		return;
	}

	if ((k > a && d < 0) || (k < a && d > 0))
	{
		cout << 'X';
		return;
	}

	if ((k - a) % d)
	{
		cout << 'X';
		return;
	}

	cout << (k - a) / d + 1;
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