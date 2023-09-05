#include <iostream>
#include <queue>
#include <cmath>
#define N 110
#define p pair<double, double>

using namespace std;

struct node {
	double dis;
	int a, b;
};

struct cmp {
	bool operator()(node a, node b)
	{
		return a.dis > b.dis;
	}
};

int n, root[N];
double ans;
p arr[N];
priority_queue<node, vector<node>, cmp> pq;

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i].first >> arr[i].second;
}

double distance(int i, int j)
{
	return sqrt(pow((arr[i].first - arr[j].first), 2) + pow((arr[i].second - arr[j].second), 2));
}

void init()
{
	for (int i = 1; i <= n; i++)
	{
		root[i] = i;

		for (int j = i + 1; j <= n; j++)
			pq.push({ distance(i, j), i, j });
	}
}

int find(int n)
{
	if (root[n] == n)
		return n;

	return root[n] = find(root[n]);
}

void solution()
{
	cout << fixed;
	cout.precision(4);
	init();

	while (!pq.empty())
	{
		int a = pq.top().a;
		int b = pq.top().b;
		double dis = pq.top().dis;
		pq.pop();

		int aroot = find(a);
		int broot = find(b);

		if (aroot == broot)
			continue;

		if (aroot < broot)
			root[broot] = aroot;

		else
			root[aroot] = broot;

		ans += dis;
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