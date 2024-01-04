#include <iostream>

using namespace std;

int n, arr[1010], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;

		if (arr[i] <= m)
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