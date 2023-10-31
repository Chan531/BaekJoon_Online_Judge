#include <iostream>
#include <vector>
#define N 202020
#define ll long long

using namespace std;

int n, m, q, cnt, f[N], b[N], depth[N], tree[4 * N];
vector<int> con[N];

void input()
{
	cin >> n >> m;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		con[a].push_back(b);
		con[b].push_back(a);
	}

	cin >> q;
}

void dfs(int par, int node, int lev)
{
	f[node] = ++cnt;
	depth[node] = lev;

	for (auto i : con[node])
		if (i != par)
			dfs(node, i, lev + 1);

	b[node] = cnt;
}

void update(int s, int e, int node, int idx)
{
	if (s > idx || e < idx)
		return;

	if (s == e && s == idx)
	{
		tree[node]++;
		return;
	}

	int m = (s + e) / 2;

	update(s, m, node * 2, idx);
	update(m + 1, e, node * 2 + 1, idx);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll output(int s, int e, int node, int l, int r)
{
	if (s > r || e < l)
		return 0;

	if (s >= l && e <= r)
		return tree[node];

	int m = (s + e) / 2;

	return output(s, m, node * 2, l, r) + output(m + 1, e, node * 2 + 1, l, r);
}

void solution()
{
	dfs(0, m, 1);

	while (q--)
	{
		int a, c;
		cin >> a >> c;

		if (a == 1)
			update(1, n, 1, f[c]);

		else
			cout << output(1, n, 1, f[c], b[c]) * depth[c] << '\n';
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