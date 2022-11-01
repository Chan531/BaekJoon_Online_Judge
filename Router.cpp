#include <iostream>
#include <queue>

using namespace std;

int n, m;

void input()
{
	cin >> n;
}

void solution()
{
	queue<int> q;

	while (1)
	{
		cin >> m;

		if (m == -1)
			break;

		else if (m == 0)
		{
			if (!q.empty())
				q.pop();
		}

		else
		{
			if (q.size() < n)
				q.push(m);
		}
	}

	if (q.empty())
		cout << "empty";

	else
	{
		while (!q.empty())
		{
			cout << q.front() << ' ';
			q.pop();
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