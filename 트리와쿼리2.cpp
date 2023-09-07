#include <iostream>
#include <vector>
#include <algorithm>
#define N 101010
#define K 17
#define ll long long
#define p pair<int, ll>

using namespace std;

int n, m, lev[N], u_cnt, v_cnt;
ll ans;
p st[K][N];
vector<p> con[N];

void input()
{
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		con[a].push_back({ b, c });
		con[b].push_back({ a, c });
	}

	cin >> m;
}

void dfs(int node, int par, int dis)
{
	lev[node] = lev[par] + 1;
	st[0][node].first = par;
	st[0][node].second = dis;

	for (auto i : con[node])
		if (i.first != par)
			dfs(i.first, node, i.second);
}

void set_st()
{
	for (int i = 1; i < K; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			st[i][j].first = st[i - 1][st[i - 1][j].first].first;
			st[i][j].second = st[i - 1][j].second + st[i - 1][st[i - 1][j].first].second;
		}
	}
}

void init()
{
	lev[0] = -1;
	dfs(1, 0, 0);
	set_st();
}

int go_up_1(int node, int dif)
{
	for (int i = 0; i < K; i++)
	{
		if ((1 << i) & dif)
		{
			ans += st[i][node].second;
			node = st[i][node].first;
		}
	}

	return node;
}

int go_up_2(int node, int dif)
{
	for (int i = 0; i < K; i++)
	{
		if ((1 << i) & dif)
		{
			u_cnt += (1 << i);
			node = st[i][node].first;
		}
	}

	return node;
}

int go_up_3(int node, int dif)
{
	for (int i = 0; i < K; i++)
	{
		if ((1 << i) & dif)
		{
			v_cnt += (1 << i);
			node = st[i][node].first;
		}
	}

	return node;
}

void lca_1(int u, int v)
{
	if (u == v)
		return;

	for (int i = K - 1; i >= 0; i--)
	{
		int u_next = st[i][u].first;
		int v_next = st[i][v].first;

		if (u_next != v_next)
		{
			ans += st[i][u].second + st[i][v].second;
			u = u_next;
			v = v_next;
		}
	}
	
	ans += st[0][u].second + st[0][v].second;
}

void lca_2(int u, int v)
{
	if (u == v)
		return;

	for (int i = K - 1; i >= 0; i--)
	{
		int u_next = st[i][u].first;
		int v_next = st[i][v].first;

		if (u_next != v_next)
		{
			u_cnt += (1 << i);
			v_cnt += (1 << i);
			u = u_next;
			v = v_next;
		}
	}

	u_cnt++;
	v_cnt++;
}

void solution()
{
	init();

	while (m--)
	{
		int c, u, v, k;
		ans = 0;
		cin >> c;

		if (c == 1)
		{
			cin >> u >> v;

			if (lev[u] > lev[v])
				u = go_up_1(u, lev[u] - lev[v]);

			else if (lev[u] < lev[v])
				v = go_up_1(v, lev[v] - lev[u]);

			lca_1(u, v);
			cout << ans << '\n';
		}

		else
		{
			cin >> u >> v >> k;
			k--;
			u_cnt = 0;
			v_cnt = 0;

			if (lev[u] > lev[v])
			{
				int temp_u = go_up_2(u, lev[u] - lev[v]);
				lca_2(temp_u, v);
			}

			else if (lev[u] < lev[v])
			{
				int temp_v = go_up_3(v, lev[v] - lev[u]);
				lca_2(u, temp_v);
			}

			else
				lca_2(u, v);

			int cnt = u_cnt + v_cnt;

			if (k < u_cnt)
			{
				for (int i = 0; i < K; i++)
				{
					if ((1 << i) & k)
					{
						k -= (1 << i);
						u = st[i][u].first;
					}
				}

				ans = u;
			}

			else
			{
				k = cnt - k;

				for (int i = 0; i < K; i++)
				{
					if ((1 << i) & k)
					{
						k -= (1 << i);
						v = st[i][v].first;
					}
				}

				ans = v;
			}

			cout << ans << '\n';
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