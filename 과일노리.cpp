#include <iostream>
#include <algorithm>
#define N 50500

using namespace std;

int n, ans, arr[2][N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[0][i] >> arr[1][i];
}

void solution()
{
 	for (int i = 0; i < n; i++)
	{
		int cur = ans % (arr[0][i] + arr[1][i]);
		ans += max(0, arr[1][i] - cur) + 1;
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