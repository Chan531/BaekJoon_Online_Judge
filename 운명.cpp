#include <iostream>

using namespace std;

int n, k, arr[10101];
long long ans;

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		arr[m]++;
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		ans += n - arr[m];
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