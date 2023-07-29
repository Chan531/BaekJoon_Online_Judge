#include <iostream>
#define ll long long

using namespace std;

ll n, sum = 1;

void input()
{
	cin >> n;
}

void solution()
{
	for (ll i = 1; i <= n; i++) sum *= i;
	cout << sum / 604800;
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