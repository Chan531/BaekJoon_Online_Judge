#include <iostream>
#include <vector>
#include <algorithm>
#define N 101010

using namespace std;

int n, arr[N], m, ans;
vector<int> tree[1 << 18];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> m;
}

void set_tree(int s = 1, int e = n, int node = 1)
{
	if (s == e)
	{
		tree[node].push_back(arr[s]);
		return;
	}

	set_tree(s, (s + e) / 2, node * 2);
	set_tree((s + e) / 2 + 1, e, node * 2 + 1);

	tree[node].resize(tree[node * 2].size() + tree[node * 2 + 1].size());
	merge(tree[node * 2].begin(), tree[node * 2].end(), tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(), tree[node].begin());
}

int query(int l, int r, int v, int s = 1, int e = n, int node = 1)
{
	if (l <= s && e <= r)
		return tree[node].size() - (upper_bound(tree[node].begin(), tree[node].end(), v) - tree[node].begin());

	if (l > e || r < s)
		return 0;

	return query(l, r, v, s, (s + e) / 2, node * 2) + query(l, r, v, (s + e) / 2 + 1, e, node * 2 + 1);
}

void solution()
{
	set_tree();

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		ans = query(a ^ ans, b ^ ans, c ^ ans);
		cout << ans << '\n';
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