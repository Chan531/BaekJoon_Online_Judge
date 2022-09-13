#include <iostream>
#include <queue>

using namespace std;

// ls -> ladder, snake
int n, m, map[101], ls[101];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n + m; i++)
	{
		int a, b;
		cin >> a >> b;
		ls[a] = b;
	}
}

void solution()
{
	queue<int> q;
	q.push(1);
	map[1] = 1;

	while (!q.empty())
	{
		int pos = q.front();
		int cnt = map[pos];
		q.pop();

		if (pos == 100)
		{
			cout << cnt - 1;
			break;
		}

		for (int i = 1; i < 7; i++)
		{
			int npos = pos + i;

			if (npos > 100)       // 범위를 벗어났다면 pass
				break;

			if (ls[npos])         // 뱀이거나 사다리를 만나면 적용
				npos = ls[npos];			
			
			if (map[npos])        // 이미 방문했다면 pass
				continue;

			map[npos] = cnt + 1;
			q.push(npos);
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

// 2022.09.13 12m
/*
#include <iostream>
#include <queue>

using namespace std;

int n, m, loop[101], cnt[101];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n + m; i++)
	{
		int a, b;

		cin >> a >> b;

		loop[a] = b;
	}
}

void solution()
{
	for (int i = 1; i <= 100; i++)
		cnt[i] = 1e9;

	queue<int> q;
	q.push(1);
	cnt[1] = 0;

	while (!q.empty())
	{
		int pos = q.front();
		q.pop();

		if (pos == 100)
			break;

		for (int i = 1; i <= 6; i++)
		{
			int npos = pos + i;

			if (npos > 100)
				continue;

			// 뱀 또는 사다리 칸이라면 npos를 변경
			if (loop[npos] != 0)
				npos = loop[npos];

			if (cnt[npos] > cnt[pos] + 1)
			{
				cnt[npos] = cnt[pos] + 1;
				q.push(npos);
			}
		}
	}

	cout << cnt[100];
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
*/