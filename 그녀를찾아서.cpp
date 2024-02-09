#include <iostream>
#include <vector>
#include <queue>
#define p pair<int, double>

using namespace std;

struct info {
	int cur, idx;
	double per;
};

int n, m;
double ans[4];
vector<p> con[4];

void input()
{
	cin >> n >> m;

	while (m--)
	{
		char a, b;
		double c;
		cin >> a >> b >> c;

		con[a - 'A'].push_back({ b - 'A', c });
	}
}

void bfs(int node)
{
	queue<info> q;
	q.push({ node, 0, 0.25 });

	while (!q.empty())
	{
		info cur = q.front();
		q.pop();

		if (cur.idx == n)
		{
			ans[cur.cur] += cur.per;
			continue;
		}

		for (auto i : con[cur.cur])
			q.push({ i.first, cur.idx + 1, cur.per * i.second });
	}
}

void solution()
{
	cout << fixed;
	cout.precision(2);

	for (int i = 0; i < 4; i++)
		bfs(i);

	for (auto i : ans)
		cout << i * 100 << '\n';
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