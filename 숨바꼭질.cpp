#include <iostream>
#include <queue>
#define p pair<int, int>
#define N 100000

using namespace std;

int n, k;
bool visited[N + 1];

void input()
{
	cin >> n >> k;
}

void solution()
{
	queue<p> q;
	q.push({ n, 0 });
	visited[n] = 1;

	while (!q.empty())
	{
		int pos = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (pos == k)
		{
			cout << cnt;
			break;
		}

		if (pos + 1 <= N && !visited[pos + 1])
		{
			visited[pos + 1] = 1;
			q.push({ pos + 1, cnt + 1 });
		}

		if (pos - 1 >= 0 && !visited[pos - 1])
		{
			visited[pos - 1] = 1;
			q.push({ pos - 1, cnt + 1 });
		}

		if (pos * 2 <= N && !visited[pos * 2])
		{
			visited[pos * 2] = 1;
			q.push({ pos * 2, cnt + 1 });
		}
	}
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