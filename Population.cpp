#include <iostream>

using namespace std;

int p, t;

void input()
{
	cin >> p >> t;
}

void solution()
{
	cout << p - t / 7 + t / 4 << '\n';
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