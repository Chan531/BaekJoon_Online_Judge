#include <iostream>
#include <queue>
#define p pair<int, int>

using namespace std;

int a, k;
bool check[1000001];

void input()
{
	cin >> a >> k;
}

void solution()
{
	queue<p> q;
	q.push({ a, 0 });
	check[a] = 1;

	while (!q.empty())
	{
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == k)
		{
			cout << cnt;
			break;
		}

		if (cur < 1000000 && !check[cur + 1])
		{
			q.push({ cur + 1, cnt + 1 });
			check[cur + 1] = 1;
		}

		if (cur <= 500000 && !check[cur * 2])
		{
			q.push({ cur * 2, cnt + 1 });
			check[cur * 2] = 1;
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