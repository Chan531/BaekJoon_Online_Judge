#include <iostream>
#include <vector>

using namespace std;

int n, ans;

void solve()
{
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;

		ans = 0;
		for (int i = 1; i <= n; i++)
			ans += i * i;
		cout << ans << '\n';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}