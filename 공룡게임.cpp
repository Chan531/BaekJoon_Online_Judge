#include <iostream>
#include <algorithm>
#include <cstring>
#define N 5050
#define ll long long
#define p pair<int, int>

using namespace std;

int n, a, b, x, y;
p arr[N];
ll dp[N][N], ans;

void input()
{
	cin >> n >> a >> b >> x >> y;

	for (int i = 1; i <= n; i++)
		cin >> arr[i].first >> arr[i].second;
}

ll game(int jidx, int sidx)
{
	if (jidx == n || sidx == n)
		return 0;

	if (dp[jidx][sidx] != -1)
		return dp[jidx][sidx];

	int next = max(jidx, sidx) + 1;
	ll ret = 1e15;

	// jump able
	if (arr[next].second % 2 && arr[next].first - arr[jidx].first >= a)
		ret = min(ret, game(next, sidx) + x);

	// slide able
	if (arr[next].second > 1 && arr[next].first - arr[sidx].first >= b)
		ret = min(ret, game(jidx, next) + y);

	return dp[jidx][sidx] = ret;
}

void solution()
{
	memset(dp, -1, sizeof(dp));
	arr[0].first = -1e9;
	ans = game(0, 0);
	ans < 1e15 ? cout << ans : cout << -1;
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