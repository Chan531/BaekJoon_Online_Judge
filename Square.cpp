#include <iostream>

using namespace std;

void solve()
{
	int n, m;
	cin >> n;

	while (n--)
	{
		cin >> m;
		
		int ans = 0;

		for (int i = 1; i <= m; i++)
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