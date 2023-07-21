#include <iostream>

using namespace std;

int n;
long long sum;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		long long c;
		cin >> c;

		sum += c % n;
		sum %= n;
	}

	sum ? cout << "NO\n" : cout << "YES\n";
	sum = 0;
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}