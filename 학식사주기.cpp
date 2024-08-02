#include <iostream>

using namespace std;

int n, m, ans, arr[11];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> m;
}

void solution()
{
	while (m--)
	{
		int a;
		cin >> a;
		ans += arr[a];
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