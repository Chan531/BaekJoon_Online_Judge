#include <iostream>
#include <queue>
#include <algorithm>
#define N 101010
#define p pair<int, int>

using namespace std;

struct node {
	int c, a, b;
};

struct cmp {
	bool operator()(node a, node b) {
		return a.c > b.c;
	}
};

int n, m, root[N], ans, val;
priority_queue<node, vector<node>, cmp> pq;

int find(int n)
{
	if (root[n] == n)
		return n;

	return root[n] = find(root[n]);
}

void input()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ c, a, b });
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
		root[i] = i;

	while (!pq.empty())
	{
		node cur = pq.top();
		pq.pop();

		int aroot = find(cur.a);
		int broot = find(cur.b);

		if (aroot == broot)
			continue;

		if (aroot < broot)
			root[broot] = aroot;

		else
			root[aroot] = broot;

		ans += cur.c;
		val = max(val, cur.c);
	}

	cout << ans - val;
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