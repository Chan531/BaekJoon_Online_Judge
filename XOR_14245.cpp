#include <iostream>
#define N 505050

using namespace std;

int n, m, arr[N], tree[N * 4], lazy[N * 4];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> m;
}

int init(int s, int e, int node)
{
	if (s == e)
		return tree[node] = arr[s];

	int m = (s + e) / 2;
	return tree[node] = init(s, m, node * 2) ^ init(m + 1, e, node * 2 + 1);
}

void check(int s, int e, int node)
{
	if (lazy[node])
	{
		if (!((e - s) % 2)) tree[node] ^= lazy[node];

		if (s != e)
		{
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}

		lazy[node] = 0;
	}
}

void update(int s, int e, int node, int l, int r, int val)
{
	check(s, e, node);

	if (s > r || e < l)
		return;

	if (s >= l && e <= r)
	{
		if (!((e - s) % 2)) tree[node] ^= val;
		if (s != e)
		{
			lazy[node * 2] ^= val;
			lazy[node * 2 + 1] ^= val;
		}
		return;
	}

	int m = (s + e) / 2;
	update(s, m, node * 2, l, r, val);
	update(m + 1, e, node * 2 + 1, l, r, val);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}

int output(int s, int e, int node, int idx)
{
	check(s, e, node);

	if (s > idx || e < idx)
		return 0;

	if (s  == idx && s == e)
		return tree[node];

	int m = (s + e) / 2;
	return output(s, m, node * 2, idx) ^ output(m + 1, e, node * 2 + 1, idx);
}

void solution()
{
	init(0, n - 1, 1);

	while (m--)
	{
		int a, b, c, d;
		cin >> a;

		if (a == 1)
		{
			cin >> b >> c >> d;
			update(0, n - 1, 1, b, c, d);
		}

		else
		{
			cin >> b;
			cout << output(0, n - 1, 1, b) << '\n';
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