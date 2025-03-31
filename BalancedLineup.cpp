#include <iostream>
#include <algorithm>
#define N 50505

using namespace std;

int n, q, arr[N], tree[N * 4][2];

void input()
{
	cin >> n >> q;

	for (int i = 1; i <= n; i++) cin >> arr[i];
}

int initMax(int s, int e, int node)
{
	if (s == e)
		return tree[node][0] = arr[s];

	int m = (s + e) / 2;
	return tree[node][0] = max(initMax(s, m, node * 2), initMax(m + 1, e, node * 2 + 1));
}

int initMin(int s, int e, int node)
{
	if (s == e)
		return tree[node][1] = arr[s];

	int m = (s + e) / 2;
	return tree[node][1] = min(initMin(s, m, node * 2), initMin(m + 1, e, node * 2 + 1));
}

int getMax(int s, int e, int l, int r, int node)
{
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return tree[node][0];
	int m = (s + e) / 2;
	return max(getMax(s, m, l, r, node * 2), getMax(m + 1, e, l, r, node * 2 + 1));
}

int getMin(int s, int e, int l, int r, int node)
{
	if (s > r || e < l) return 1e9;
	if (s >= l && e <= r) return tree[node][1];
	int m = (s + e) / 2;
	return min(getMin(s, m, l, r, node * 2), getMin(m + 1, e, l, r, node * 2 + 1));
}

void solution()
{
	initMax(1, n, 1);
	initMin(1, n, 1);

	while (q--)
	{
		int a, b;
		cin >> a >> b;
		cout << getMax(1, n, a, b, 1) - getMin(1, n, a, b, 1) << '\n';
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