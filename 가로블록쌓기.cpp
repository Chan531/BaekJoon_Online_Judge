#include <iostream>
#include <vector>
#include <algorithm>
#define N 202020
#define p pair<int, int>

using namespace std;

int n, ans, r[N], tree[N * 4], lazy[N * 4];
p arr[N];
vector<int> v;

void input()
{
	cin >> n;
}

void check(int s, int e, int node)
{
	if (!lazy[node]) return;

	if (s != e)
	{
		tree[node * 2] = lazy[node];
		tree[node * 2 + 1] = lazy[node];
		lazy[node * 2] = lazy[node];
		lazy[node * 2 + 1] = lazy[node];
	}

	lazy[node] = 0;
}

int put(int s, int e, int node, int l, int r)
{
	check(s, e, node);

	if (s > r || e < l)
		return 0;

	if (s >= l && e <= r)
	{
		tree[node]++;
		return tree[node];
	}

	int m = (s + e) / 2;
	return tree[node] = max(put(s, m, node * 2, l, r), put(m + 1, e, node * 2 + 1, l, r));
}

void update(int s, int e, int node, int l, int r, int val)
{
	check(s, e, node);

	if (s > r || e < l)
		return;

	if (s >= l && e <= r)
	{
		tree[node] = val;
		lazy[node] = tree[node];
		return;
	}

	int m = (s + e) / 2;
	update(s, m, node * 2, l, r, val);
	update(m + 1, e, node * 2 + 1, l, r, val);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i].second >> arr[i].first;
		arr[i].second += arr[i].first - 1;
		v.push_back(arr[i].first);
		v.push_back(arr[i].second);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 1; i <= n; i++)
	{
		arr[i].first = lower_bound(v.begin(), v.end(), arr[i].first) - v.begin();
		arr[i].second = lower_bound(v.begin(), v.end(), arr[i].second) - v.begin();
	}

	int e = v.size() - 1;

	for (int i = 1; i <= n; i++)
	{
		int val = put(0, e, 1, arr[i].first, arr[i].second);
		ans = max(ans, val);
		update(0, e, 1, arr[i].first, arr[i].second, val);
	}

	cout << ans;
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