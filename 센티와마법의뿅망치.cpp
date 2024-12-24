#include <iostream>
#include <queue>

using namespace std;

int n, h, t;
priority_queue<int> pq;

void input()
{
	cin >> n >> h >> t;

	while (n--)
	{
		int k;
		cin >> k;
		pq.push(k);
	}
}

void solution()
{
	for (int i = 0; i < t; i++)
	{
		int t = pq.top();
		pq.pop();

		if (t < h)
		{
			cout << "YES\n" << i;
			return;
		}

		if (t == 1)
		{
			pq.push(t);
			break;
		}

		pq.push(t / 2);
	}

	if (pq.top() < h)
		cout << "YES\n" << t;
	else
		cout << "NO\n" << pq.top();
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