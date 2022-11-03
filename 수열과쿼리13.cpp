#include <iostream>
#define N 100001
#define MOD 1000000007
#define p pair<long long, long long>

using namespace std;

int n, m, arr[N];
long long seg[N * 4];
p lazy[N * 4];
// mul, add

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> m;
}

long long settree(int start, int end, int node)
{
	if (start == end)
		return seg[node] = arr[start];

	int mid = (start + end) / 2;

	return seg[node] = (settree(start, mid, node * 2) + settree(mid + 1, end, node * 2 + 1)) % MOD;
}

void setlazy()
{
	for (int i = 1; i <= 4 * n; i++)
		lazy[i] = { 1, 0 };
}

void lazy_prop(int node, long long mul, long long add)
{
	lazy[node * 2].first *= mul;
	lazy[node * 2].first %= MOD;
	lazy[node * 2].second *= mul;
	lazy[node * 2].second %= MOD;
	lazy[node * 2].second += add;
	lazy[node * 2].second %= MOD;

	lazy[node * 2 + 1].first *= mul;
	lazy[node * 2 + 1].first %= MOD;
	lazy[node * 2 + 1].second *= mul;
	lazy[node * 2 + 1].second %= MOD;
	lazy[node * 2 + 1].second += add;
	lazy[node * 2 + 1].second %= MOD;
}

void check(int start, int end, int node)
{
	if (lazy[node].first == 1 && lazy[node].second == 0)
		return;

	seg[node] *= lazy[node].first;
	seg[node] += (end - start + 1) * lazy[node].second;
	seg[node] %= MOD;

	if (start != end)
		lazy_prop(node, lazy[node].first, lazy[node].second);

	lazy[node].first = 1;
	lazy[node].second = 0;
}

void update(int start, int end, int left, int right, int node, long long mul, long long add)
{
	check(start, end, node);

	if (start > right || end < left)
		return;

	if (start >= left && end <= right)
	{
		seg[node] *= mul;
		seg[node] %= MOD;
		seg[node] += (end - start + 1) * add;
		seg[node] %= MOD;

		if (start != end)
			lazy_prop(node, mul, add);

		return;
	}

	int mid = (start + end) / 2;

	update(start, mid, left, right, node * 2, mul, add);
	update(mid + 1, end, left, right, node * 2 + 1, mul, add);

	seg[node] = (seg[node * 2] + seg[node * 2 + 1]) % MOD;
}

long long output(int start, int end, int left, int right, int node)
{
	check(start, end, node);

	if (start > right || end < left)
		return 0;

	if (start >= left && end <= right)
		return seg[node];

	int mid = (start + end) / 2;

	return (output(start, mid, left, right, node * 2) + output(mid + 1, end, left, right, node * 2 + 1)) % MOD;
}

void solution()
{
	settree(1, n, 1);
	setlazy();

	while (m--)
	{
		int com, x, y, v;

		cin >> com;

		// +
		if (com == 1)
		{
			cin >> x >> y >> v;
			update(1, n, x, y, 1, 1, v);
		}

		// *
		else if (com == 2)
		{
			cin >> x >> y >> v;
			update(1, n, x, y, 1, v, 0);
		}

		// =
		else if (com == 3)
		{
			cin >> x >> y >> v;
			update(1, n, x, y, 1, 0, v);
		}

		else
		{
			cin >> x >> y;
			cout << output(1, n, x, y, 1) << '\n';
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
	cout.tie(NULL);

	solve();
	return 0;
}