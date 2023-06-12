#include <iostream>
#include <queue>
#define p pair<int, int>

using namespace std;

int n, k;
queue<p> q;

void input()
{
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			int num;
			cin >> num;
			q.push({ num, i });
		}
	}
}

void solution()
{
	while (q.size() != 1)
	{
		int cnt = q.front().first - 1;
		q.pop();

		while (cnt--)
		{
			q.push(q.front());
			q.pop();
		}
	}

	cout << q.front().second << ' ' << q.front().first;
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