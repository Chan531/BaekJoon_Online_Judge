#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define N 202020
#define ll long long
#define p pair<ll, int>

using namespace std;

int n, m, note[N], sum, dp[N];	// dp -> 현재까지 왔을 때 가장 많이 챙길 수 있는 노트의 개수
ll dis[N];
vector<p> con[N];
vector<int> ans;

void input()
{
	cin >> n >> m;

	while (m--)
	{
		int a, b;
		ll c;
		cin >> a >> b >> c;

		con[a].push_back({ c, b });
		con[b].push_back({ c, a });
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> note[i];
		sum += note[i];
	}
}

void solution()
{
	for (int i = 2; i <= n; i++)
		dis[i] = 1e16;

	for (int i = 1; i <= n; i++)
		dp[i] = -1;

	priority_queue<p> pq;
	pq.push({ 0, 1 });
	dp[1] = note[1];

	while (!pq.empty())
	{
		int cur = pq.top().second;
		ll cost = pq.top().first * -1;
		pq.pop();

		if (dis[cur] < cost)
			continue;

		for (int i = 0; i < con[cur].size(); i++)
		{
			int next = con[cur][i].second;
			ll ncost = cost + con[cur][i].first;

			if (dis[next] > ncost)
			{
				pq.push({ ncost * -1, next });
				dis[next] = ncost;
				dp[next] = max(dp[next], dp[cur] + note[next]);
			}

			else if (dis[next] == ncost)
				dp[next] = max(dp[next], dp[cur] + note[next]);
		}
	}

	if (dp[n] != sum)
	{
		cout << -1;
		return;
	}

	while (n != 1)
	{
		ans.push_back(n);

		for (int i = 0; i < con[n].size(); i++)
		{
			int pre = con[n][i].second;
			ll cost = con[n][i].first;

			if (dis[n] != dis[pre] + cost)
				continue;

			if (dp[n] != dp[pre] + note[n])
				continue;

			n = pre;
			break;
		}
	}

	ans.push_back(1);

	cout << ans.size() << '\n';

	while (!ans.empty())
	{
		cout << ans.back() << ' ';
		ans.pop_back();
	}
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