#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define N 100001
#define K 18
#define p pair<int, int>

using namespace std;

struct info {
	int node, minval, maxval;
};

int n, k, lev[N], ans_minval, ans_maxval;
vector<p> con[N];
info sparse_table[K][N];

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

	cin >> k;
}

void dfs(int node, int par)
{
	lev[node] = lev[par] + 1;

	for (auto i : con[node])
	{
		if (lev[i.first])
			continue;

		sparse_table[0][i.first] = { node, i.second, i.second };
		dfs(i.first, node);
	}
}

void set_sparse_table()
{
	for (int i = 1; i < K; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int par = sparse_table[i - 1][j].node;
			sparse_table[i][j].node = sparse_table[i - 1][par].node;
			sparse_table[i][j].minval = min(sparse_table[i - 1][j].minval, sparse_table[i - 1][par].minval);
			sparse_table[i][j].maxval = max(sparse_table[i - 1][j].maxval, sparse_table[i - 1][par].maxval);
		}
	}
}

void init()
{
	dfs(1, 0);
	set_sparse_table();
}

info go_to(int node, int dif)
{
	int go_to_minval = 1e9;
	int go_to_maxval = 0;

	for (int i = 0; i < K; i++)
	{
		if ((1 << i) & dif)
		{
			go_to_minval = min(go_to_minval, sparse_table[i][node].minval);
			go_to_maxval = max(go_to_maxval, sparse_table[i][node].maxval);
			node = sparse_table[i][node].node;
		}
	}

	return { node, go_to_minval, go_to_maxval };
}

void solution()
{
	init();

	while (k--)
	{
		int a, b;
		cin >> a >> b;

		int alev = lev[a];
		int blev = lev[b];

		if (alev > blev)
			swap(a, b);

		info match_lev = go_to(b, abs(blev - alev));
		b = match_lev.node;
		ans_minval = match_lev.minval;
		ans_maxval = match_lev.maxval;

		if (a == b)
		{
			cout << ans_minval << ' ' << ans_maxval << '\n';
			continue;
		}

		for (int i = K - 1; i >= 0; i--)
		{
			info a_top = go_to(a, (1 << i));
			info b_top = go_to(b, (1 << i));

			if (a_top.node != b_top.node)
			{
				ans_minval = min({ ans_minval, a_top.minval, b_top.minval });
				ans_maxval = max({ ans_maxval, a_top.maxval, b_top.maxval });
				a = a_top.node;
				b = b_top.node;
			}
		}

		ans_minval = min({ ans_minval, sparse_table[0][a].minval, sparse_table[0][b].minval });
		ans_maxval = max({ ans_maxval, sparse_table[0][a].maxval, sparse_table[0][b].maxval });

		cout << ans_minval << ' ' << ans_maxval << '\n';
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