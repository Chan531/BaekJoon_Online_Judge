#include <iostream>
#include <algorithm>
#include <cmath>
#define p pair<int, int>

using namespace std;

struct node {
	long long val;
	int a, b;
};

int n, root[100000];
long long  ans;
p x[100000], y[100000], z[100000];
node arr[300000];

bool cmp(node a, node b)
{
	return a.val < b.val;
}

void input()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> x[i].first >> y[i].first >> z[i].first;
		x[i].second = i;
		y[i].second = i;
		z[i].second = i;
	}
}

void xdif(int idx, int i)
{
	arr[idx].val = abs(x[i].first - x[i - 1].first);
	arr[idx].a = x[i].second;
	arr[idx].b = x[i - 1].second;
}

void ydif(int idx, int i)
{
	arr[idx].val = abs(y[i].first - y[i - 1].first);
	arr[idx].a = y[i].second;
	arr[idx].b = y[i - 1].second;
}

void zdif(int idx, int i)
{
	arr[idx].val = abs(z[i].first - z[i - 1].first);
	arr[idx].a = z[i].second;
	arr[idx].b = z[i - 1].second;
}

int find(int m)
{
	if (root[m] == m)
		return m;

	return root[m] = find(root[m]);
}

void solution()
{
	sort(x, x + n);
	sort(y, y + n);
	sort(z, z + n);

	int idx = 0;

	for (int i = 1; i < n; i++)
	{
		xdif(idx++, i);
		ydif(idx++, i);
		zdif(idx++, i);
	}

	sort(arr, arr + 3 * (n - 1), cmp);

	for (int i = 0; i < n; i++)
		root[i] = i;

	for (int i = 0; i < 3 * (n - 1); i++)
	{
		int val = arr[i].val;
		int a = arr[i].a;
		int b = arr[i].b;

		int aroot = find(a);
		int broot = find(b);

		if (aroot == broot)
			continue;

		ans += val;

		if (aroot < broot)
			root[broot] = aroot;

		else
			root[aroot] = broot;
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
	cout.tie(NULL);

	solve();
	return 0;
}