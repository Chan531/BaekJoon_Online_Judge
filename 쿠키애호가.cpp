#include <iostream>

using namespace std;

int n, c;

void input()
{
	cin >> n >> c;
}

void solution()
{
	n% c ? cout << n / c + 1 << '\n' : cout <<  n / c << '\n';
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
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