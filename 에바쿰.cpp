#include <iostream>
#define N 1000100
#define ll long long

using namespace std;

int n, q1, q2;
ll arr[N], tree[N * 4][2];

void input()
{
	cin >> n >> q1 >> q2;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

ll init(int s, int e, int node)
{
	if (s == e)
		return tree[node][0] = arr[s];

	int m = (s + e) / 2;
	return tree[node][0] = init(s, m, node * 2) + init(m + 1, e, node * 2 + 1);
}

void lazy(int s, int e, int node)
{
	if (tree[node][1] != 0)
	{
		tree[node][0] += tree[node][1] * (e - s + 1);

		if (s != e)
		{
			tree[node * 2][1] += tree[node][1];
			tree[node * 2 + 1][1] += tree[node][1];
		}

		tree[node][1] = 0;
	}
}

ll output(int s, int e, int l, int r, int node)
{
	if (s > r || e < l) return 0;
	lazy(s, e, node);
	if (s >= l && e <= r) return tree[node][0];
	int m = (s + e) / 2;
	return output(s, m, l, r, node * 2) + output(m + 1, e, l, r, node * 2 + 1);
}

void update(int s, int e, int l, int r, int node, ll val)
{
	lazy(s, e, node);
	if (s > r || e < l) return;
	if (s >= l && e <= r)
	{
		tree[node][0] += val * (e - s + 1);
		if (s != e)
		{
			tree[node * 2][1] += val;
			tree[node * 2 + 1][1] += val;
		}
		return;
	}

	int m = (s + e) / 2;
	update(s, m, l, r, node * 2, val);
	update(m + 1, e, l, r, node * 2 + 1, val);
	tree[node][0] = tree[node * 2][0] + tree[node * 2 + 1][0];
}

void solution()
{
	init(1, n, 1);

	for (int i = 0; i < q1 + q2; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
			cout << output(1, n, b, c, 1) << '\n';

		else
		{
			ll d;
			cin >> d;
			update(1, n, b, c, 1, d);
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