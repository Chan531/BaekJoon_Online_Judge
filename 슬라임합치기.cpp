#include <iostream>

using namespace std;

int n, arr[100], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 1; i < n; i++)
	{
		ans += arr[i] * arr[i - 1];
		arr[i] += arr[i - 1];
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
	cout.tie(NULL);

	solve();
	return 0;
}