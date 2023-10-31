#include <iostream>
#include <vector>
#include <algorithm>
#define N 101010
#define ll long long

using namespace std;

struct node1 {
	int idx;
	ll v;
};

struct node2 {
	int k, idx, i, j;
};

bool cmp(node2 a, node2 b)
{
	return a.k < b.k;
}

int n, m, idx;
ll arr[N], tree[N * 4], ans[N];
vector<node1> o;
vector<node2> t;

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c, d;
		cin >> a;

		if (a == 1)
		{
			cin >> b >> c;
			o.push_back({ b, c });
		}

		else
		{
			cin >> b >> c >> d;
			t.push_back({ b, idx++, c, d });
		}
	}
}

ll init(int s = 1, int e = n, int node = 1)
{
	if (s == e)
		return tree[node] = arr[s];

	int m = (s + e) / 2;

	return tree[node] = init(s, m, node * 2) + init(m + 1, e, node * 2 + 1);
}

void update(int s, int e, int node, int idx, ll v)
{
	if (s > idx || e < idx)
		return;

	if (s == e && s == idx)
	{
		tree[node] = v;
		return;
	}

	int m = (s + e) / 2;

	update(s, m, node * 2, idx, v);
	update(m + 1, e, node * 2 + 1, idx, v);
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
	sort(t.begin(), t.end(), cmp);
	init();

	int st = 0;

	for (node2 a : t)
	{
		while (a.k > st)
		{
			update(1, n, 1, o[st].idx, o[st].v);
			st++;
		}

		ans[a.idx] = output(1, n, 1, a.i, a.j);
	}

	for (int i = 0; i < idx; i++)
		cout << ans[i] << '\n';
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