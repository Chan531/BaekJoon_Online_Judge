#include <iostream>
#include <queue>

using namespace std;

int n, info[1001][1001], root[1001];
long long ans;

struct node {
	int val, x, y;
};

int check(int a)
{
	if (root[a] == a)
		return a;

	return root[a] = check(root[a]);
}

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> info[i][j];
}

void solution()
{
	priority_queue<node> pq;

	for (int i = 1; i <= n; i++)
	{
		root[i] = i;
		
		for (int j = i + 1; j <= n; j++)
			pq.push({ info[i][j] * -1, i, j });
	}

	while (!pq.empty())
	{
		long long val = pq.top().val * -1;
		int x = pq.top().x;
		int y = pq.top().y;
		pq.pop();

		int xroot = check(x);
		int yroot = check(y);

		if (xroot == yroot)
			continue;

		if (xroot < yroot)
			root[yroot] = xroot;

		else
			root[xroot] = yroot;

		ans += val;
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