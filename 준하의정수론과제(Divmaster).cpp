#include <iostream>
#include <cmath>
#include <algorithm>
#define N 101010
#define M 1001010
#define ll long long

using namespace std;

int n, q, arr[N], cnt[M];
ll tree[N * 4][2];

void input()
{
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void init(int s = 1, int e = n, int node = 1)
{
	if (s == e) {
		tree[node][0] = arr[s];
		tree[node][1] = arr[s];
		return;
	}

	int m = (s + e) / 2;
	init(s, m, node * 2);
	init(m + 1, e, node * 2 + 1);
	tree[node][0] = tree[node * 2][0] + tree[node * 2 + 1][0];
	tree[node][1] = max(tree[node * 2][1], tree[node * 2 + 1][1]);

}

int setcnt(int num)
{
	int ret = 0;

	for (int i = 1; i <= sqrt(num); i++)
	{
		if (num % i)
			continue;

		i == sqrt(num) ? ret++ : ret += 2;
	}

	return ret;
}

void update(int s, int e, int node, int l, int r)
{
	if (s > r || e < l || tree[node][1] <= 2)
		return;

	if (s == e)
	{
		if (cnt[arr[s]] == 0)
			cnt[arr[s]] = setcnt(arr[s]);

		tree[node][0] = cnt[arr[s]];
		tree[node][1] = cnt[arr[s]];
		arr[s] = cnt[arr[s]];
		return;
	}

	int m = (s + e) / 2;
	update(s, m, node * 2, l, r);
	update(m + 1, e, node * 2 + 1, l, r);
	tree[node][0] = tree[node * 2][0] + tree[node * 2 + 1][0];
	tree[node][1] = max(tree[node * 2][1], tree[node * 2 + 1][1]);
}

ll query(int s, int e, int node, int l, int r)
{
	if (s > r || e < l)
		return 0;

	if (s >= l && e <= r)
		return tree[node][0];

	int m = (s + e) / 2;
	return query(s, m, node * 2, l, r) + query(m + 1, e, node * 2 + 1, l, r);
}

void solution()
{
	init();

	while (q--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
			update(1, n, 1, b, c);

		else
			cout << query(1, n, 1, b, c) << '\n';
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