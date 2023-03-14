#include <iostream>
#include <algorithm>
#define N 16
#define INF 1e9

using namespace std;

int n, cost[N][N], dp[N][1 << N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> cost[i][j];
}

int tsp(int pos, int visited)
{
	int ret = dp[pos][visited];

	if (ret)
		return ret;

	// 만약 모든 점을 방문했다면
	if (visited == (1 << n) - 1)
	{
		// 원점과 연결되어있다면
		if (cost[pos][0])
			return cost[pos][0];

		// 원점과 연결되어있지 않아 돌아갈 수 없다면
		return INF;
	}

	ret = INF;

	for (int i = 0; i < n; i++)
	{
		// 길이 없다면
		if (!cost[pos][i])
			continue;

		// 만약 방문한 곳을 또 가려고 한다면
		if (visited & (1 << i))
			continue;

		ret = min(ret, tsp(i, visited | (1 << i)) + cost[pos][i]);
		cout << visited << '\n';
	}

	dp[pos][visited] = ret;
	return ret;
}

void solution()
{
	cout << tsp(0, 1);
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