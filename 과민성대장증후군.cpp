#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[101010], s, ans;

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		s = max(0, s + arr[i]);

		if (s >= m)
			ans++;
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