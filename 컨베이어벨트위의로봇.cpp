#include <iostream>
#include <queue>
#define N 101

using namespace std;

int n, k, s, e, cnt, ans, arr[N * 2];
bool rob[N * 2];
queue<int> q;

void input()
{
	cin >> n >> k;

	for (int i = 0; i < 2 * n; i++)
		cin >> arr[i];
}

void rotate()
{
	s--;
	e--;

	if (s < 0)
		s = 2 * n - 1;

	if (e < 0)
		e = 2 * n - 1;
}

void move()
{
	int size = q.size();

	for (int i = 0; i < size; i++)
	{
		int cur = q.front();
		q.pop();

		if (cur == e)
		{
			rob[cur] = 0;
			continue;
		}

		int next = (cur + 1) % (2 * n);

		if (arr[next] && !rob[next])
		{
			arr[next]--;
			if (!arr[next]) cnt++;
			rob[cur] = 0;
			if (next == e) continue;
			rob[next] = 1;
			q.push(next);
		}

		else
			q.push(cur);
	}
}

void solution()
{
	s = 0;
	e = n - 1;

	for (int i = 1; ; i++)
	{
		rotate();
		move();

		if (arr[s] && !rob[s])
		{
			rob[s] = 1;
			arr[s]--;
			if (!arr[s]) cnt++;
			q.push(s);
		}

		if (cnt >= k)
		{
			ans = i;
			break;
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

	solve();
	return 0;
}