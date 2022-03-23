#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int t, n, a, b, arr[100001], visited[1000001];

struct node {
	int n, cnt;
};

void sosu()   // 소수 기록
{
	arr[1] = 1;
	for (int i = 2; i <= 100000; i++)
	{
		if (!arr[i])
		{
			for (int j = i * 2; j <= 100000; j += i)
				arr[j] = 1;
		}
	}
}

void input()
{
	cin >> n >> a >> b;
}

void solution()
{
	for (int i = a; i <= b; i++)      // 범위 안에 소수가 존재하는지 확인
	{
		if (!arr[i])
			break;

		if (i == b)
		{
			cout << -1 << '\n';
			return;
		}
	}

	memset(visited, 0, sizeof(int) * 1000001);
	int ans = -1;

	queue<node> q;
	q.push({ n,0 });
	visited[n] = 1;

	while (!q.empty())
	{
		int pos = q.front().n;
		int cnt = q.front().cnt;
		q.pop();

		if (pos >= a && pos <= b)
		{
			if (!arr[pos])
			{
				ans = cnt;
				break;
			}
		}

		if (!visited[pos / 3])
		{
			visited[pos / 3] = 1;
			q.push({ pos / 3, cnt + 1 });
		}

		if (!visited[pos / 2])
		{
			visited[pos / 2] = 1;
			q.push({ pos / 2, cnt + 1 });
		}

		if (!visited[pos + 1])
		{
			visited[pos + 1] = 1;
			q.push({ pos + 1, cnt + 1 });
		}

		if (pos >= 1 && !visited[pos - 1])
		{
			visited[pos - 1] = 1;
			q.push({ pos - 1, cnt + 1 });
		}
	}

	cout << ans << '\n';
}

void solve()
{
	sosu();
	cin >> t;
	while (t--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}