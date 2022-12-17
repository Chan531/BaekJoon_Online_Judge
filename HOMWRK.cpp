#include <iostream>

using namespace std;

int n;
long long a, b;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		cin >> a >> b;
		cout << a + b << ' ' << a * b << '\n';
	}
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