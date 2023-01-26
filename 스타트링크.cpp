#include <iostream>
#include <queue>
#define p pair<int, int>
#define N 1000000

using namespace std;

int f, s, g, u, d, ans = -1;
bool visited[N + 1];

void input()
{
	cin >> f >> s >> g >> u >> d;
}

void solution()
{
	queue<p> q;
	q.push({ s, 0 });
	visited[s] = 1;

	while (!q.empty())
	{
		int pos = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (pos == g)
		{
			ans = cnt;
			break;
		}

		if (pos + u <= f && !visited[pos + u])
		{
			q.push({ pos + u, cnt + 1 });
			visited[pos + u] = 1;
		}

		if (pos - d >= 1 && !visited[pos - d])
		{
			q.push({ pos - d, cnt + 1 });
			visited[pos - d] = 1;
		}
	}

	ans == -1 ? cout << "use the stairs" : cout << ans;
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