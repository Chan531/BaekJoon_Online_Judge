#include <iostream>

using namespace std;

int n, arr[1000], ans[1000];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	int temp = arr[0];

	for (int i = n - 1; i > 0; i--)
	{
		if (i % 2) temp += arr[i];
		else temp -= arr[i];
	}

	ans[1] = temp / 2;
	ans[0] = arr[0] - ans[1];

	for (int i = 2; i < n - 1; i++)
		ans[i] = arr[i - 1] - ans[i - 1];

	ans[n - 1] = arr[n - 1] - ans[0];

	for (int i = 0; i < n; i++)
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