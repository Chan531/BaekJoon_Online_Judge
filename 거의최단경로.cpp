#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define N 505
#define M 10010
#define p pair<int, int>

using namespace std;

struct node {
	int next, dis, idx;
};

int n, m, s, d, dis[N], val[N][N];
vector<node> con[N];
vector<p> pre[N];
bool check[M];

void reset_dis()
{
	for (int i = 0; i < n; i++)
		dis[i] = 1e9;
}

void reset_rest()
{
	for (int i = 0; i < n; i++)
	{
		con[i].clear();
		pre[i].clear();
	}

	memset(check, 0, sizeof(check));
}

void input()
{
	cin >> s >> d;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		con[a].push_back({ b, c, i });
		pre[b].push_back({ a, i });
		val[a][b] = c;
	}
}

void init()
{
	priority_queue<p> pq;
	pq.push({ 0, s });
	dis[s] = 0;

	while (!pq.empty())
	{
		int cost = pq.top().first * -1;
		int cur = pq.top().second;
		pq.pop();

		if (dis[cur] < cost || cur == d)
			continue;

		for (auto i : con[cur])
		{
			int next = i.next;
			int ncost = cost + i.dis;

			if (dis[next] <= ncost)
				continue;

			pq.push({ ncost * -1, next });
			dis[next] = ncost;
		}
	}
}

void trace(int cur)
{
	if (cur == s)
		return;

	for (int i = 0; i < pre[cur].size(); i++)
	{
		p temp = pre[cur][i];

		if (dis[cur] != dis[temp.first] + val[temp.first][cur] || check[temp.second])
			continue;

		check[temp.second] = 1;
		trace(temp.first);
	}
}

void solution()
{
	init();
	trace(d);
	reset_dis();

	int ans = -1;
	priority_queue<p> pq;
	pq.push({ 0, s });
	dis[s] = 0;

	while (!pq.empty())
	{
		int cost = pq.top().first * -1;
		int cur = pq.top().second;
		pq.pop();

		if (dis[cur] < cost)
			continue;

		if (cur == d)
		{
			ans = cost;
			break;
		}

		for (auto i : con[cur])
		{
			int next = i.next;
			int ncost = cost + i.dis;
			int idx = i.idx;

			if (dis[next] <= ncost || check[idx])
				continue;

			pq.push({ ncost * -1, next });
			dis[next] = ncost;
		}
	}

	cout << ans << '\n';
}

void solve()
{
	while (1)
	{
		cin >> n >> m;

		if (!n && !m)
			break;

		reset_dis();
		input();
		solution();
		reset_rest();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}