#include <iostream>
#include <unordered_map>
#define ll long long

using namespace std;

ll n, p, q;
unordered_map<ll, ll> num;

void input()
{
	cin >> n >> p >> q;
}

ll dp(ll i)
{
	if (i == 0)
		return 1;

	if (num[i])
		return num[i];

	return num[i] = dp(i / p) + dp(i / q);
}

void solution()
{
	cout << dp(n);
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