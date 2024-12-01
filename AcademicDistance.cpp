#include <iostream>
#include <cmath>

using namespace std;

int n, arr[101][2], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1];
}

void solution()
{
	for (int i = 1; i < n; i++)
		ans += abs(arr[i][0] - arr[i - 1][0]) + abs(arr[i][1] - arr[i - 1][1]);

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