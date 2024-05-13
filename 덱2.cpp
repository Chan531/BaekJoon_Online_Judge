#include <iostream>
#include <deque>

using namespace std;

int n;
deque<int> dq;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int a, b;
		cin >> a;

		if (a == 1)
		{
			cin >> b;
			dq.push_front(b);
		}

		else if (a == 2)
		{
			cin >> b;
			dq.push_back(b);
		}

		else if (a == 3)
		{
			int c;
			if (dq.empty())
				c = -1;
			else
			{
				c = dq.front();
				dq.pop_front();
			}
			cout << c << '\n';
		}

		else if (a == 4)
		{
			int c;
			if (dq.empty())
				c = -1;
			else
			{
				c = dq.back();
				dq.pop_back();
			}
			cout << c << '\n';
		}

		else if (a == 5)
			cout << dq.size() << '\n';

		else if (a == 6)
			cout << dq.empty() << '\n';

		else if (a == 7)
		{
			if (dq.empty())
				cout << -1 << '\n';

			else
				cout << dq.front() << '\n';
		}

		else if (a == 8)
		{
			if (dq.empty())
				cout << -1 << '\n';

			else
				cout << dq.back() << '\n';
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