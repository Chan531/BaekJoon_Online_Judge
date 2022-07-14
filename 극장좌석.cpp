#include <iostream>

using namespace std;

int n, m, seat[41], vip[41];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
		cin >> vip[i];
}

void solution()
{
	seat[0] = 1;
	seat[1] = 1;

	for (int i = 2; i <= n; i++)
		seat[i] = seat[i - 1] + seat[i - 2];

	int ans = 1, idx = 0;
	vip[m] = n + 1;

	for (int i = 0; i <= m; i++)
	{
		ans *= seat[vip[i] - idx - 1];
		idx = vip[i];
	}

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
	cout.tie(NULL);

	solve();
	return 0;
}