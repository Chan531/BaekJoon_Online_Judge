#include <iostream>

using namespace std;

int n;
long long m, arr[50], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	cin >> m;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % m)
			ans += arr[i] / m * m + m;

		else
			ans += arr[i];
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