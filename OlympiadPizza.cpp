#include <iostream>
#include <queue>
#define p pair<int, int>

using namespace std;

int n, ans[1010];
queue<p> q;

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		q.push({ k, i });
	}
}

void solution()
{
	for (int i = 1; ; i++)
	{
		if (q.empty()) break;

		p cur = q.front();
		q.pop();

		if (cur.first - 1 == 0)
		{
			ans[cur.second] = i;
			continue;
		}

		q.push({ cur.first - 1, cur.second });
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
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