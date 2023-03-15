#include <iostream>
#include <cstring>
#include <algorithm>
#define N 10
#define INF 1e9
#define p pair<int, int>

using namespace std;

int n, k, dp[N][1 << N];
p cost[N][N];

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> cost[i][j].first;
			cost[i][j].second = (1 << i | 1 << j);
		}
	}
}

int tsp(int cur, int visited)
{
	if (dp[cur][visited] != -1)
		return dp[cur][visited];

	if (visited == (1 << n) - 1)
		return 0;

	int ret = INF;

	for (int i = 0; i < n; i++)
	{
		if ((visited | cost[cur][i].second) == visited)
			continue;

		ret = min(ret, tsp(i, visited | cost[cur][i].second) + cost[cur][i].first);
	}

	dp[cur][visited] = ret;
	return ret;
}

void solution()
{
	for (int i = 0; i < n; i++)				// 거쳐감
	{
		for (int j = 0; j < n; j++)			// 시작
		{
			for (int k = 0; k < n; k++)		// 종료	
			{
				if (cost[j][k].first > cost[j][i].first + cost[i][k].first)
				{
					cost[j][k].first = cost[j][i].first + cost[i][k].first;
					cost[j][k].second = cost[j][i].second | cost[i][k].second;
				}
			}
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << tsp(k, 1 << k);
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