#include <iostream>
#include <algorithm>
#define N 101010

using namespace std;

struct info {
	int minv, maxv, val;
};

int n, arr[N], q;
info tree[N * 4];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> q;
}

void init(int s, int e, int node)
{
	if (s == e)
	{
		tree[node].minv = arr[s];
		tree[node].maxv = arr[e];
		return;
	}

	int m = (s + e) / 2;
	init(s, m, node * 2);
	init(m + 1, e, node * 2 + 1);

	tree[node].minv = min(tree[node * 2].minv, tree[node * 2 + 1].minv);
	tree[node].maxv = max(tree[node * 2].maxv, tree[node * 2 + 1].maxv);
	tree[node].val = max({ tree[node * 2].val, tree[node * 2 + 1].val, tree[node * 2 + 1].maxv - tree[node * 2].minv });
}

void update(int s, int e, int node, int idx, int v)
{
	if (s == e && s == idx)
	{
		arr[s] = v;
		tree[node].minv = arr[s];
		tree[node].maxv = arr[e];
		return;
	}

	if (s > idx || e < idx)
		return;

	int m = (s + e) / 2;
	update(s, m, node * 2, idx, v);
	update(m + 1, e, node * 2 + 1, idx, v);

	tree[node].minv = min(tree[node * 2].minv, tree[node * 2 + 1].minv);
	tree[node].maxv = max(tree[node * 2].maxv, tree[node * 2 + 1].maxv);
	tree[node].val = max({ tree[node * 2].val, tree[node * 2 + 1].val, tree[node * 2 + 1].maxv - tree[node * 2].minv });
}

info query(int s, int e, int node, int l, int r)
{
	if (e < l || s > r)
		return { (int) 1e9, (int) -1e9, 0 };

	if (s >= l && e <= r)
		return tree[node];

	int m = (s + e) / 2;
	info left = query(s, m, node * 2, l, r);
	info right = query(m + 1, e, node * 2 + 1, l, r);

	return { min(left.minv, right.minv), max(left.maxv, right.maxv), max({left.val, right.val, right.maxv - left.minv}) };
}

void solution()
{
	init(1, n, 1);

	while (q--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
			update(1, n, 1, b, c);

		else
			cout << query(1, n, 1, b, c).val << '\n';
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