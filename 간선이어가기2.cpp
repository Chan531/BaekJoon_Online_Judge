#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define N 5050
#define p pair<int, int>

using namespace std;

struct cmp {
	bool operator()(p a, p b) {
		return a.first > b.first;
	}
};

int n, m, s, t, dp[N];
vector<p> con[N];
priority_queue<p, vector<p>, cmp> pq;

void input()
{
	cin >> n >> m;

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		con[a].push_back({ c, b });
		con[b].push_back({ c, a });
	}

	cin >> s >> t;
}

void solution()
{
	for (int i = 1; i <= n; i++)
		dp[i] = 1e9;

	dp[s] = 0;
	pq.push({ 0, s });

	while (!pq.empty())
	{
		p cur = pq.top();
		pq.pop();

		if (cur.second == t)
		{
			cout << cur.first;
			break;
		}

		if (dp[cur.second] < cur.first)
			continue;

		for (int i = 0; i < con[cur.second].size(); i++)
		{
			int next = con[cur.second][i].second;
			
			if (dp[next] < con[cur.second][i].first + cur.first)
				continue;

			dp[next] = con[cur.second][i].first + cur.first;
			pq.push({ dp[next], next });
		}
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