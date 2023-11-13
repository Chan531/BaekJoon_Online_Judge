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
	dq.push_back(n);

	int num = n;

	while (dq.size() != n)
	{
		dq.push_front(--num);

		for (int i = 0; i < num; i++)
		{
			dq.push_front(dq.back());
			dq.pop_back();
		}
	}

	while (!dq.empty())
	{
		cout << dq.front() << ' ';
		dq.pop_front();
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