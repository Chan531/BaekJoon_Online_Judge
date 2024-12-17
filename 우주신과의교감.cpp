#include <iostream>
#include <queue>
#include <cmath>
#define N 1010
#define p pair<double, double>

using namespace std;

struct node {
	double d;
	int a, b;
};

struct cmp {
	bool operator()(node a, node b)
	{
		return a.d > b.d;
	}
};

int n, m, root[N], cnt[N];
double d[N][N], ans;
p arr[N];
priority_queue<node, vector<node>, cmp> pq;

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i].first >> arr[i].second;
}

int find(int n)
{
	if (root[n] == n) return n;
	return root[n] = find(root[n]);
}

double cal(int i, int j)
{
	return sqrt(pow(abs(arr[i].first - arr[j].first), 2) + pow(abs(arr[i].second - arr[j].second), 2));
}

bool uf(int a, int b)
{
	if (a == b)
		return 0;

	else if (a < b)
	{
		root[b] = a;
		cnt[a] += cnt[b];
	}

	else
	{
		root[a] = b;
		cnt[b] += cnt[a];
	}

	return 1;
}

void solution()
{
	cout << fixed;
	cout.precision(2);

	for (int i = 1; i <= n; i++) root[i] = i, cnt[i] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			d[i][j] = cal(i, j);
			pq.push({ d[i][j], i, j });
		}

	}

	while (m--)
	{
		int a, b;
		cin >> a >> b;

		int aroot = find(a);
		int broot = find(b);
		uf(aroot, broot);
	}

	while (!pq.empty())
	{
		if (cnt[1] == n) break;
		node cur = pq.top();
		pq.pop();

		int aroot = find(cur.a);
		int broot = find(cur.b);

		if (uf(aroot, broot)) ans += cur.d;
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