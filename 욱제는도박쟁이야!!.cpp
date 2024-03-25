#include <iostream>
#include <cmath>
#define N 10100

using namespace std;

int n, arr[2][N], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < 2 * n; i++)
		cin >> arr[i / n][i % n];
}

void solution()
{
	for (int i = 0; i < n; i++)
		ans += abs(arr[0][i]) + abs(arr[1][i]);

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