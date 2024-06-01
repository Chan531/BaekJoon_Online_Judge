#include <iostream>
#define N 101010
#define ll long long

using namespace std;

int n, c[N], idx;
ll l[N], r[N], ans = 1e16;

void input()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i < n; i++) cin >> l[i], l[i] += l[i - 1];
	for (int i = 1; i < n; i++) cin >> r[i], r[i] += r[i - 1];
}

void solution()
{
	for (int i = 1; i < n; i++)
	{
		ll val = l[i - 1] + c[i] + r[n - 1] - r[i - 1];

		if (ans > val)
		{
			ans = val;
			idx = i;
		}
	}

	cout << idx << ' ' << ans;
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