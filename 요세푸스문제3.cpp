#include <iostream>

using namespace std;

int n, k, ans = 1;

void solve()
{
	cin >> n >> k;
	for (int i = 2; i <= n; i++)
		ans = (ans + k - 1) % i + 1;
	cout << ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}