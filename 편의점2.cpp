#include <iostream>
#include <algorithm>
#include <cmath>
#define N 101010
#define ll long long

using namespace std;

int n, a[N], b[N];
ll ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
}

void solution()
{
	sort(a, a + n);
	sort(b, b + n);

	for (int i = 0; i < n; i++)
		ans += abs(a[i] - a[n / 2]) + abs(b[i] - b[n / 2]);

	cout << ans;
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