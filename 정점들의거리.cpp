#include <iostream>
#include <vector>
#define N 40001
#define K 16
#define p pair<int, long long>

using namespace std;

int n, m, lev[N];
long long answer;
p sparse_table[K][N];
vector<p> con[N];

void input()
{
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		long long c;
		cin >> a >> b >> c;
		
		con[a].push_back({ b, c });
		con[b].push_back({ a, c });
	}

	cin >> m;
}

void dfs(int node, int par, int dis)
{
	lev[node] = lev[par] + 1;
	sparse_table[0][node].first = par;
	sparse_table[0][node].second = dis;

	for (auto i : con[node])
		if (i.first != par)
			dfs(i.first, node, i.second);
}

void set_sparse_table()
{
	for (int i = 1; i < K; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sparse_table[i][j].first = sparse_table[i - 1][sparse_table[i - 1][j].first].first;
			sparse_table[i][j].second = sparse_table[i - 1][j].second + sparse_table[i - 1][sparse_table[i - 1][j].first].second;
		}
	}
}

int go_up(int node, int dif)
{
	for (int i = 0; i < K; i++)
	{
		if ((1 << i) & dif)
		{
			answer += sparse_table[i][node].second;
			node = sparse_table[i][node].first;
		}
	}

	return node;
}

void lca(int a, int b)
{
	if (a == b)
		return;

	for (int i = K - 1; i >= 0; i--)
	{
		if (sparse_table[i][a].first != sparse_table[i][b].first)
		{
			answer += sparse_table[i][a].second + sparse_table[i][b].second;
			a = sparse_table[i][a].first;
			b = sparse_table[i][b].first;
		}
	}

	answer += sparse_table[0][a].second + sparse_table[0][b].second;
}

void solution()
{
	lev[0] = -1;
	dfs(1, 0, 0);
	set_sparse_table();

	while (m--)
	{
		int a, b;
		cin >> a >> b;

		answer = 0;

		if (lev[a] < lev[b])
			swap(a, b);

		a = go_up(a, lev[a] - lev[b]);
		lca(a, b);
		cout << answer << '\n';
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