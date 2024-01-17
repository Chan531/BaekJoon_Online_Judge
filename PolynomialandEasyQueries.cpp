#include <iostream>
#define N 505050
#define mod 100003
#define K 19
#define ll long long

using namespace std;

int n, q, tree[N * 4][2];
ll arr[N], sp1[K][mod], sp2[K][mod];

void input()
{
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void init()
{
	for (ll i = 0; i < mod; i++)
	{
		sp1[0][i] = (2 * i * i - 1) % mod;
		sp2[0][i] = (4 * i * i * i - 3 * i) % mod;
	}

	for (int i = 1; i < K; i++)
	{
		for (int j = 0; j < mod; j++)
		{
			sp1[i][j] = sp1[i - 1][sp1[i - 1][j]];
			sp2[i][j] = sp2[i - 1][sp2[i - 1][j]];
		}
	}
}

void lazy(int s, int e, int node)
{
	if (s != e)
	{
		tree[node * 2][0] += tree[node][0];
		tree[node * 2][1] += tree[node][1];
		tree[node * 2 + 1][0] += tree[node][0];
		tree[node * 2 + 1][1] += tree[node][1];
		tree[node][0] = 0;
		tree[node][1] = 0;
	}
}

void update1(int s, int e, int l, int r, int node)
{
	if (e < l || s > r)
		return;

	if (s >= l && e <= r)
	{
		tree[node][0]++;
		return;
	}

	int m = (s + e) / 2;
	update1(s, m, l, r, node * 2);
	update1(m + 1, e, l, r, node * 2 + 1);
}

void update2(int s, int e, int l, int r, int node)
{
	if (e < l || s > r)
		return;

	if (s >= l && e <= r)
	{
		tree[node][1]++;
		return;
	}

	int m = (s + e) / 2;
	update2(s, m, l, r, node * 2);
	update2(m + 1, e, l, r, node * 2 + 1);
}

int output(int s, int e, int idx, int node)
{
	if (s > idx || e < idx)
		return 0;

	if (tree[node][0] || tree[node][1])
		lazy(s, e, node);

	if (s == idx && s == e)
	{
		int ret = arr[idx];

		for (int i = 0; i < K; i++)
		{
			if ((1 << i) & tree[node][0])
				ret = sp1[i][ret];

			if ((1 << i) & tree[node][1])
				ret = sp2[i][ret];
		}

		tree[node][0] = 0;
		tree[node][1] = 0;

		return arr[idx] = ret;
	}

	int m = (s + e) / 2;
	return output(s, m, idx, node * 2) + output(m + 1, e, idx, node * 2 + 1);
}

void solution()
{
	init();

	while (q--)
	{
		int a;
		cin >> a;

		if (a == 1)
		{
			int b, c;
			cin >> b >> c;
			update1(1, n, b, c, 1);
		}

		else if (a == 2)
		{
			int b, c;
			cin >> b >> c;
			update2(1, n, b, c, 1);
		}

		else
		{
			int b;
			cin >> b;
			cout << output(1, n, b, 1) << '\n';
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