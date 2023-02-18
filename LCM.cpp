#include <iostream>

using namespace std;

long long a, b;

void input()
{
	cin >> a >> b;
}

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

void solution()
{
	cout << a * b / gcd(a, b) << '\n';
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