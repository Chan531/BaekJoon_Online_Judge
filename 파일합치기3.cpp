#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int testcase, k;

void solution()
{
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	long long num, ans = 0;
	cin >> k;

	while (k--)
	{
		cin >> num;
		pq.push(num);
	}

	while (pq.size() != 1)
	{
		long long a = pq.top();
		pq.pop();

		long long b = pq.top();
		pq.pop();

		pq.push(a + b);
		ans += a + b;
	}

	cout << ans << '\n';
}

void solve()
{
	cin >> testcase;
	while (testcase--)
	{
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}