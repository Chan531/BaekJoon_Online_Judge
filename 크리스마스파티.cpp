#include <iostream>

using namespace std;

int n, m, arr[101], ans[101];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 1; i <= m; i++)
	{
		int cnt = 0;

		for (int j = 1; j <= n; j++)
		{
			int k;
			cin >> k;

			if (k == arr[i])
				ans[j]++;

			else
				ans[arr[i]]++;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << '\n';
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