#include <iostream>
#include <vector>
#include <queue>
#define p pair<int, int>

using namespace std;

int a, b, n, m, ans = -1;
vector<int> con[1001];
bool check[1001];

void input()
{
	cin >> a >> b >> n >> m;

	while (m--)
	{
		int x, y;
		cin >> x >> y;

		con[x].push_back(y);
		con[y].push_back(x);
	}
}

void solution()
{
	queue<p> q;
	q.push({ a, 0 });

	while (!q.empty())
	{
		int pos = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (check[pos])
			continue;

		if (pos == b)
		{
			ans = cnt;
			break;
		}

		check[pos] = 1;

		for (auto i : con[pos])
			q.push({ i, cnt + 1 });
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