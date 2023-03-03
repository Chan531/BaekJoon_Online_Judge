#include <iostream>
#include <queue>

using namespace std;

int n, ans;

void input()
{
	cin >> n;
}

void solution()
{
	queue<int> q;
	q.push(n);

	while (!q.empty())
	{
		int m = q.front();
		q.pop();

		if (m == 1)
			continue;

		if (m % 2)
		{
			ans += (m / 2) * (m / 2 + 1);
			q.push(m / 2);
			q.push(m / 2 + 1);
		}

		else
		{
			ans += (m / 2) * (m / 2);
			q.push(m / 2);
			q.push(m / 2);
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