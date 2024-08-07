#include <iostream>
#include <algorithm>
#define N 1010100
#define TEMP -1
#define ll long long

using namespace std;

int n, q;
ll arr[N], tree[4 * N][4];	// 0 -> sum, 1 -> max, 2 -> max2, 3 -> cnt

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> q;
}

void update(int node)
{
	tree[node][0] = tree[node * 2][0] + tree[node * 2 + 1][0];
	if (tree[node * 2][1] == tree[node * 2 + 1][1])
	{
		tree[node][1] = tree[node * 2][1];
		tree[node][2] = max(tree[node * 2][2], tree[node * 2 + 1][2]);
		tree[node][3] = tree[node * 2][3] + tree[node * 2 + 1][3];
	}
	else
	{
		if (tree[node * 2][1] > tree[node * 2 + 1][1])
		{
			tree[node][1] = tree[node * 2][1];
			tree[node][2] = max(tree[node * 2][2], tree[node * 2 + 1][1]);
			tree[node][3] = tree[node * 2][3];
		}
		else
		{
			tree[node][1] = tree[node * 2 + 1][1];
			tree[node][2] = max(tree[node * 2 + 1][2], tree[node * 2][1]);
			tree[node][3] = tree[node * 2 + 1][3];
		}
	}
}

void init(int s, int e, int node)
{
	if (s == e)
	{
		tree[node][0] = arr[s];
		tree[node][1] = arr[s];
		tree[node][2] = TEMP;
		tree[node][3] = 1;
		return;
	}

	int m = (s + e) / 2;
	init(s, m, node * 2);
	init(m + 1, e, node * 2 + 1);
	update(node);
}

void check(int s, int e, int node)
{
	if (s == e)
		return;

	for (int i = node * 2; i <= node * 2 + 1; i++)
	{
		if (tree[node][1] < tree[i][1])
		{
			tree[i][0] -= tree[i][3] * (tree[i][1] - tree[node][1]);
			tree[i][1] = tree[node][1];
		}
	}
}

void q1(int s, int e, int node, int l, int r, ll val)
{
	check(s, e, node);

	if (s > r || e < l || tree[node][1] <= val)
		return;

	if (s >= l && e <= r && tree[node][2] < val)
	{
		tree[node][0] -= (tree[node][1] - val) * tree[node][3];
		tree[node][1] = val;
		check(s, e, node);
		return;
	}

	int m = (s + e) / 2;
	q1(s, m, node * 2, l, r, val);
	q1(m + 1, e, node * 2 + 1, l, r, val);
	update(node);
}

ll q2(int s, int e, int node, int l, int r)
{
	check(s, e, node);

	if (s > r || e < l)
		return 0;

	if (s >= l && e <= r)
		return tree[node][1];

	int m = (s + e) / 2;
	return max(q2(s, m, node * 2, l, r), q2(m + 1, e, node * 2 + 1, l, r));
}

ll q3(int s, int e, int node, int l, int r)
{
	check(s, e, node);

	if (s > r || e < l)
		return 0;

	if (s >= l && e <= r)
		return tree[node][0];

	int m = (s + e) / 2;
	return q3(s, m, node * 2, l, r) + q3(m + 1, e, node * 2 + 1, l, r);
}

void solution()
{
	init(1, n, 1);

	while (q--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			ll d;
			cin >> d;
			q1(1, n, 1, b, c, d);
		}

		else if (a == 2)
			cout << q2(1, n, 1, b, c) << '\n';

		else
			cout << q3(1, n, 1, b, c) << '\n';
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