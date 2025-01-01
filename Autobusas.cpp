#include <iostream>
#include <algorithm>

using namespace std;

int n, k, cur, ans;

void input()
{
	cin >> n >> k;
}

void solution()
{
	while (n--)
	{
		int a, b;
		cin >> a >> b;

		cur += a - b;
		ans = max(ans, cur - k);
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

	solve();
	return 0;
}