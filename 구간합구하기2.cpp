#include <iostream>
#include <vector>

using namespace std;
vector<long long> v(1000001);
vector<pair<long long, long long>> tree(2097153);

long long setsum(int start, int end, int node)
{
	if (start == end)
		return tree[node].first = v[start];

	int mid = (start + end) / 2;

	return tree[node].first = setsum(start, mid, node * 2) + setsum(mid + 1, end, node * 2 + 1);
}

void updatelazy(int start, int end, int node)
{
	if (tree[node].second != 0)
	{
		tree[node].first += (end - start + 1) * tree[node].second;
		if (start != end)
		{
			tree[node * 2].second += tree[node].second;
			tree[node * 2 + 1].second += tree[node].second;
		}
		tree[node].second = 0;
	}
}

long long sectionsum(int start, int end, int node, int left, int right)
{
	updatelazy(start, end, node);

	if (start > right || end < left)
		return 0;

	if (start >= left && end <= right)
		return tree[node].first;

	int mid = (start + end) / 2;

	return sectionsum(start, mid, node * 2, left, right) + sectionsum(mid + 1, end, node * 2 + 1, left, right);
}

void changenum(int start, int end, int node, int left, int right, long long vc)
{
	updatelazy(start, end, node);

	if (start > right || end < left)
		return;

	if (start >= left && end <= right)
	{
		tree[node].first += (end - start + 1) * vc;
		if (start != end)
		{
			tree[node * 2].second += vc;
			tree[node * 2 + 1].second += vc;
		}
		return;
	}

	int mid = (start + end) / 2;
	changenum(start, mid, node * 2, left, right, vc);
	changenum(mid + 1, end, node * 2 + 1, left, right, vc);
	tree[node].first = tree[node * 2].first + tree[node * 2 + 1].first;
}

int main(void)
{
	int n, m, k, a, b, c;
	long long num, d;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v[i] = num;
	}
	setsum(0, n - 1, 1);
	for (int i = 0; i < m + k; i++)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c >> d;
			changenum(0, n - 1, 1, b - 1, c - 1, d);
		}
		else
		{
			cin >> b >> c;
			cout << sectionsum(0, n - 1, 1, b - 1, c - 1) << '\n';
		}
	}
	return 0;
}

// Sqrt Decomposition

/*

#include <iostream>
#include <cmath>
#define N 1000001
#define M 1001

using namespace std;

int n, m, q;
long long arr[N], sum[M], change[M];

void input()
{
	cin >> n;

	for (int i = 0; i < 2; i++)
	{
		int k;
		cin >> k;

		q += k;
	}

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void init()
{
	for (int i = 1; i <= n; i++)
		sum[i / m] += arr[i];
}

void update(int l, int r, long long val)
{
	while (l % m != 0 && l <= r)
	{
		sum[l / m] += val;
		arr[l++] += val;
	}

	while ((r + 1) % m != 0 && l <= r)
	{
		sum[r / m] += val;
		arr[r--] += val;
	}

	while (l <= r)
	{
		change[l / m] += val;
		sum[l / m] += val * m;
		l += m;
	}
}

void output(int l, int r)
{
	long long val = 0;

	while (l % m != 0 && l <= r)
	{
		val += change[l / m];
		val += arr[l++];
	}

	while ((r + 1) % m != 0 && l <= r)
	{
		val += change[r / m];
		val += arr[r--];
	}

	while (l <= r)
	{
		val += sum[l / m];
		l += m;
	}

	cout << val << '\n';
}

void solution()
{
	m = sqrt(n);
	init();

	while (q--)
	{
		int a, b, c;
		long long d;
		cin >> a;

		if (a == 1)
		{
			cin >> b >> c >> d;
			update(b, c, d);
		}

		else
		{
			cin >> b >> c;
			output(b, c);
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

*/