#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define p pair<int, long long>
#define N 5001

using namespace std;

int n;
long long ans;
vector<p> path[N];
bool visited[N];

void input()
{
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		path[a].push_back({ b, c });
		path[b].push_back({ a, c });
	}
}

void solution()
{
	queue<p> q;
	q.push({ 1, 0 });
	visited[1] = 1;

	while (!q.empty())
	{
		int pos = q.front().first;
		long long dis = q.front().second;
		q.pop();

		ans = max(ans, dis);

		for (int i = 0; i < path[pos].size(); i++)
		{
			long long npos = path[pos][i].first;
			long long ndis = dis + path[pos][i].second;

			if (visited[npos])
				continue;

			visited[npos] = 1;
			q.push({ npos, ndis });
		}
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