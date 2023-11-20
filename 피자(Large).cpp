#include <iostream>
#define ll long long

using namespace std;

ll n;

void input()
{
	cin >> n;
}

void solution()
{
	cout << n * (n - 1) / 2;
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