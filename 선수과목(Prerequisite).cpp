#include <iostream>
#include <vector>
#include <queue>
#define N 1010
#define p pair<int, int>

using namespace std;

int n, m, cnt[N], ans[N];
vector<int> v[N];
queue<p> q;

void input()
{
	cin >> n >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		cnt[b]++;
		v[a].push_back(b);
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
		if (!cnt[i])
			q.push({ i, 1 });

	while (!q.empty())
	{
		int cur = q.front().first;
		int sem = q.front().second;
		q.pop();

		ans[cur] = sem;

		for (auto i : v[cur])
			if (!--cnt[i])
				q.push({ i, sem + 1 });
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