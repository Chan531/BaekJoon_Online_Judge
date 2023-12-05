#include <iostream>
#define mod 1000000007
#define ll long long

using namespace std;

ll n;

void input()
{
	cin >> n;
}

ll dc(ll idx)
{
	if (idx == 0)
		return 1;

	if (idx == 1)
		return 2;

	ll val = dc(idx / 2);

	if (idx % 2)
		return (val * val * 2) % mod;

	return val * val % mod;
}

void solution()
{
	if (n == 0)
	{
		cout << 1;
		return;
	}

	cout << dc(n - 1);
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