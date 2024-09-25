#include <iostream>
#include <cmath>
#include <algorithm>
#define N 101010
#define INF 1000000000000000
#define ll long long

using namespace std;

int n, q;
ll arr[N], tree[N * 4][3], ad[N * 4], di[N * 4];	// 0 -> sum, 1 -> max, 2 -> min

void input()
{
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> arr[i];
}

void update(int node)
{
	tree[node][0] = tree[node * 2][0] + tree[node * 2 + 1][0];
	tree[node][1] = max(tree[node * 2][1], tree[node * 2 + 1][1]);
	tree[node][2] = min(tree[node * 2][2], tree[node * 2 + 1][2]);
}

void init(int s, int e, int node)
{
	if (s == e)
	{
		tree[node][0] = arr[s];
		tree[node][1] = arr[s];
		tree[node][2] = arr[s];
		return;
	}

	int m = (s + e) / 2;
	init(s, m, node * 2);
	init(m + 1, e, node * 2 + 1);
	update(node);
}

void lazy_add(int s, int e, int node)
{
	tree[node][0] += ad[node] * (e - s + 1);
	tree[node][1] += ad[node];
	tree[node][2] += ad[node];
	if (s != e)
	{
		ad[node * 2] += ad[node];
		ad[node * 2 + 1] += ad[node];
	}
	ad[node] = 0;
}

void lazy_div(int s, int e, int node)
{
	tree[node][0] = (di[node] + ad[node]) * (e - s + 1);
	tree[node][1] = di[node] + ad[node];
	tree[node][2] = di[node] + ad[node];
	if (s != e)
	{
		di[node * 2] = di[node];
		ad[node * 2] = ad[node];
		di[node * 2 + 1] = di[node];
		ad[node * 2 + 1] = ad[node];
	}
	di[node] = INF;
	ad[node] = 0;
}

void check(int s, int e, int node)
{
	if (!ad[node] && di[node] == INF) return;

	/* add만 발생할 시 */
	if (di[node] == INF) lazy_add(s, e, node);

	/* div도 해야하는 경우 */
	else lazy_div(s, e, node);
}

void add(int s, int e, int node, int l, int r, ll val)
{
	check(s, e, node);
	if (s > r || e < l) return;
	if (s >= l && e <= r)
	{
		if (di[node] == INF)
		{
			ad[node] += val;
			check(s, e, node);
			return;
		}
	}

	int m = (s + e) / 2;
	add(s, m, node * 2, l, r, val);
	add(m + 1, e, node * 2 + 1, l, r, val);
	update(node);
}

void div(int s, int e, int node, int l, int r, ll val)
{
	check(s, e, node);
	if (s > r || e < l) return;
	if (s >= l && e <= r)
	{
		if (floor((double)tree[node][1] / val) == floor((double)tree[node][2] / val))
		{
			di[node] = floor((double)tree[node][1] / val);
			check(s, e, node);
			return;
		}

		else if (tree[node][1] == tree[node][2] + 1)
		{
			ad[node] = floor((double)tree[node][2] / val) - tree[node][2];
			check(s, e, node);
			return;
		}
	}

	int m = (s + e) / 2;
	div(s, m, node * 2, l, r, val);
	div(m + 1, e, node * 2 + 1, l, r, val);
	update(node);
}

ll min_val(int s, int e, int node, int l, int r)
{
	check(s, e, node);
	if (s > r || e < l) return INF;
	if (s >= l && e <= r) return tree[node][2];

	int m = (s + e) / 2;
	return min(min_val(s, m, node * 2, l, r), min_val(m + 1, e, node * 2 + 1, l, r));
}

ll sum(int s, int e, int node, int l, int r)
{
	check(s, e, node);
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return tree[node][0];

	int m = (s + e) / 2;
	return sum(s, m, node * 2, l, r) + sum(m + 1, e, node * 2 + 1, l, r);
}

void solution()
{
	init(0, n - 1, 1);

	for (int i = 1; i < 4 * n; i++)
		di[i] = INF;

	while (q--)
	{
		int a, b, c;
		ll d;
		cin >> a;

		if (a == 1)
		{
			cin >> b >> c >> d;
			add(0, n - 1, 1, b, c, d);
		}

		else if (a == 2)
		{
			cin >> b >> c >> d;
			div(0, n - 1, 1, b, c, d);
		}

		else if (a == 3)
		{
			cin >> b >> c;
			cout << min_val(0, n - 1, 1, b, c) << '\n';
		}

		else
		{
			cin >> b >> c;
			cout << sum(0, n - 1, 1, b, c) << '\n';
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