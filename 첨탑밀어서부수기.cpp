#include <iostream>

using namespace std;

int n, ans, arr[5050505];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];
}

void solution()
{
	for (int i = 1; i < n; i++)
	{
		ans++;

		while (i < n && arr[i] > arr[i + 1])
			i++;
	}

	if (arr[n - 1] <= arr[n]) ans++;

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