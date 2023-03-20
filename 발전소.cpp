#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 16

using namespace std;

struct node {
	int status, cnt, val;
};

int n, cost[N][N], start_status, on, p, dp[1 << N], ans = 1e9;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> cost[i][j];

	for (int i = 0; i < n; i++)
	{
		char sta;
		cin >> sta;

		if (sta == 'Y')
		{
			start_status += (1 << i);
			on++;
		}
	}

	cin >> p;
}

void solution()
{
	memset(dp, -1, sizeof(dp));
	queue<node> q;
	q.push({ start_status, on, 0 });
	dp[start_status] = 0;

	while (!q.empty())
	{
		int status = q.front().status;
		int cnt = q.front().cnt;
		int val = q.front().val;
		q.pop();

		if (dp[status] < val)
			continue;

		if (cnt >= p)
		{
			ans = min(ans, val);
			continue;
		}

		for (int i = 0; i < n; i++)
		{
			// 고장난 연구소라면 pass
			if (!((1 << i) & status))
				continue;

			for (int j = 0; j < n; j++)
			{
				// 고장나지 않은 연구소라면 pass
				if ((1 << j) & status)
					continue;

				int next_status = status | (1 << j);
				int next_val = val + cost[i][j];

				// 처음 가는 경로라면
				if (dp[next_status] == -1)
				{
					q.push({ next_status, cnt + 1, next_val });
					dp[next_status] = next_val;
				}

				// 큐에 넣은 경로인데 더 짧은 경로라면
				else if (dp[next_status] > next_val)
				{
					q.push({ next_status, cnt + 1, next_val });
					dp[next_status] = next_val;
				}
			}
		}
	}

	ans == 1e9 ? cout << -1 : cout << ans;
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