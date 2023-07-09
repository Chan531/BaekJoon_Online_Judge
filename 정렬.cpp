#include <iostream>

using namespace std;

int n, arr[101010], ans;
bool check[101010][2];	// up, down

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void solution()
{
	check[0][0] = 1;
	check[n + 1][1] = 1;
	arr[0] = -1e9;
	arr[n + 1] = 1e9;

	for (int i = 1; i <= n; i++)
		if (arr[i - 1] <= arr[i] && check[i - 1][0])
			check[i][0] = 1;

	for (int i = n; i > 0; i--)
		if (arr[i] <= arr[i + 1] && check[i + 1][1])
			check[i][1] = 1;

	for (int i = 1; i <= n; i++)
		if (check[i - 1][0] && check[i + 1][1] && (arr[i - 1] <= arr[i + 1]))
			ans++;

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