#include <iostream>

using namespace std;

int n, m, arr[50], ans = 1;

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	if (n == 0)
	{
		cout << 0;
		return;
	}

	int rest = m;

	for (int i = 0; i < n; i++)
	{
		if (rest < arr[i])
		{
			rest = m - arr[i];
			ans++;
			continue;
		}

		rest -= arr[i];
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