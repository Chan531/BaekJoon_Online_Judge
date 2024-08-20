#include <iostream>
#include <queue>

using namespace std;

int n, k, a, b;
priority_queue<int> pq;

void input()
{
	cin >> n >> k >> a >> b;
}

void solution()
{
	for (int i = 0; i < n; i++)
		pq.push(k * -1);

	for (int i = 0; ; i++)
	{
		if ((pq.top() * -1) - i <= 0)
		{
			cout << i;
			break;
		}

		for (int j = 0; j < a; j++)
		{
			int cur = pq.top();
			pq.pop();
			pq.push(cur - b);
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

	solve();
	return 0;
}