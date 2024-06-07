#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

int n, m, ans;
ll x, y, k, arr[101];

void input()
{
	cin >> n >> m;

	for (int i = m - 1; i >= 0; i--)
		cin >> k, x += k * pow(10, i);

	for (int i = m - 1; i >= 0; i--)
		cin >> k, y += k * pow(10, i);

	for (int i = 0; i < n; i++) cin >> arr[i];
}

void reset()
{
	x = 0;
	y = 0;
	ans = 0;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		ll temp = 0;

		for (int j = m - 1; j >= 0; j--)
			temp += arr[(i + m - 1 - j) % n] * pow(10, j);

		if (temp >= x && temp <= y)
			ans++;
	}

	cout << ans << '\n';
	reset();
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