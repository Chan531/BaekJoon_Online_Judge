#include <iostream>
#define N 100000

using namespace std;

int n, ans, tree[N * 4][2];

void input()
{
	cin >> n;
}

void check(int s, int e, int idx, int node)
{
	if (s > idx || e < idx)
		return;

	int m = (s + e) / 2;

	// lazy prop
	if (tree[node][1])
	{
		if (s != e)
		{
			tree[node * 2][1] += tree[node][1];
			tree[node * 2][0] += (m - s + 1) * tree[node][1];
			tree[node * 2 + 1][1] += tree[node][1];
			tree[node * 2 + 1][0] += (e - m) * tree[node][1];
		}

		tree[node][1] = 0;
	}

	if (s == idx && s == e)
	{
		ans += tree[node][0];
		tree[node][0] = 0;
		return;
	}

	check(s, m, idx, node * 2);
	check(m + 1, e, idx, node * 2 + 1);
	tree[node][0] = tree[node * 2][0] + tree[node * 2 + 1][0];
}

void update(int s, int e, int l, int r, int node)
{
	if (s > r || e < l)
		return;

	if (s >= l && e <= r)
	{
		tree[node][1]++;
		tree[node][0] += (e - s + 1);
		return;
	}

	int m = (s + e) / 2;

	update(s, m, l, r, node * 2);
	update(m + 1, e, l, r, node * 2 + 1);
	tree[node][0] = tree[node * 2][0] + tree[node * 2 + 1][0];
}

void solution()
{
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		ans = 0;
		check(1, N, a, 1);
		check(1, N, b, 1);
		cout << ans << '\n';
		update(1, N, a + 1, b - 1, 1);
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