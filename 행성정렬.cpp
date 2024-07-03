#include <iostream>
#define ll long long

using namespace std;

int n;
ll ans = 1, arr[101010];

void input()
{
	cin >> n;

	for (int i = 1; i <= n - 2; i++)
		cin >> arr[i];
}

int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

void solution()
{
	for (int i = 1; i <= n - 2; i++)
		ans = ans * arr[i] / gcd(ans, arr[i]);

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