#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int n, m, num, maxnum, ans = 0;
priority_queue<int, vector<int>, greater<int>> narr;
priority_queue<int> parr;

void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num >= 0)
			parr.push(num);
		else
			narr.push(num);
	}
}

void solution()
{
	if (!parr.empty() && !narr.empty())
	{
		if (abs(narr.top()) > parr.top())
			maxnum = narr.top();
		else
			maxnum = parr.top();
	}

	else
		!parr.empty() ? maxnum = parr.top() : maxnum = narr.top();

	while (!parr.empty())
	{
		if (parr.top() == maxnum)
			ans += parr.top();
		else
			ans += 2 * parr.top();

		int idx = 0;
		while (!parr.empty() && idx != m)
		{
			parr.pop();
			idx++;
		}
	}

	while (!narr.empty())
	{
		if (narr.top() == maxnum)
			ans += abs(narr.top());
		else
			ans += 2 * abs(narr.top());
		
		int idx = 0;
		while (!narr.empty() && idx != m)
		{
			narr.pop();
			idx++;
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