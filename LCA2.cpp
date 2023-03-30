#include <iostream>
#include <vector>
#include <cmath>
#define N 100001
#define K 17

using namespace std;

int n, m, sparse_table[K][N], lev[N];
vector<int> con[N];

void input()
{
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		con[a].push_back(b);
		con[b].push_back(a);
	}

	cin >> m;
}

void dfs(int node, int par_node)
{
	sparse_table[0][node] = par_node;
	lev[node] = lev[par_node] + 1;
	for (auto i : con[node])
		if (par_node != i)
			dfs(i, node);
}

void set_sparse_table()
{
	for (int i = 1; i < K; i++)
		for (int j = 1; j <= n; j++)
			sparse_table[i][j] = sparse_table[i - 1][sparse_table[i - 1][j]];
}

int go_up(int node, int dif)
{
	for (int i = 0; i < K; i++)
		if ((1 << i) & dif)
			node = sparse_table[i][node];

	return node;
}

int lca(int a, int b)
{
	if (a == b)
		return a;

	for (int i = K - 1; i >= 0; i--)
	{
		if (sparse_table[i][a] != sparse_table[i][b])
		{
			a = sparse_table[i][a];
			b = sparse_table[i][b];
		}
	}

	return sparse_table[0][a];
}

void solution()
{
	lev[0] = -1;
	dfs(1, 0);
	set_sparse_table();

	while (m--)
	{
		int a, b;
		cin >> a >> b;

		if (lev[a] < lev[b])
			swap(a, b);

		a = go_up(a, lev[a] - lev[b]);

		cout << lca(a, b) << '\n';
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
	cout.tie(NULL);

	solve();
	return 0;
}