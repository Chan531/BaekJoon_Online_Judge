#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> pq;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int m;
		cin >> m;

		for (int i = 0; i < m; i++)
		{
			int k;
			cin >> k;
			pq.push(k);
		}

		if (m)
			continue;

		if (pq.empty())
			cout << -1 << '\n';

		else
		{
			cout << pq.top() << '\n';
			pq.pop();
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