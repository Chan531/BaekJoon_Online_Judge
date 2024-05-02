#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int n, k, ans, arr[101010][3], sum[101010];

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
}

int check(int a, int b)
{
	for (int i = 0; i < n; i++)
		sum[i] = arr[i][a] + arr[i][b];

	sort(sum, sum + n, greater<int>());
	return accumulate(sum, sum + k, 0);
}

void solution()
{
	ans = max(ans, check(0, 1));
	ans = max(ans, check(0, 2));
	ans = max(ans, check(1, 2));
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