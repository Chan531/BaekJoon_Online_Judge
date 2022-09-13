#include <iostream>
#include <algorithm>

using namespace std;

int n, cost[11][11], ans = 1e9;
bool visited[11];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> cost[i][j];
}

void backtrack(int start, int idx, int cnt, int val)
{
	// 시간을 확 줄여줌
	if (val >= ans)
		return;

	if (cnt == n)
	{
		if (cost[idx][start] == 0)
			return;

		ans = min(ans, val + cost[idx][start]);
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			continue;

		if (cost[idx][i] == 0)
			continue;

		visited[i] = 1;
		backtrack(start, i, cnt + 1, val + cost[idx][i]);
		visited[i] = 0;
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		visited[i] = 1;
		backtrack(i, i, 1, 0);
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