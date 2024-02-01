#include <iostream>

using namespace std;

int n, arr[101][2], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i][0];

	for (int i = 0; i < n; i++)
		cin >> arr[i][1];
}

void solution()
{
	for (int i = 0; i < n; i++)
		if (arr[i][0] > arr[i][1])
			ans += arr[i][0] - arr[i][1];

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