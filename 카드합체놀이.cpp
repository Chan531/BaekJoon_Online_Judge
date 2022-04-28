#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
long long num, ans = 0;
priority_queue<long long, vector<long long>, greater<long long>> pq;

void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		pq.push(num);
	}
}

void solution()
{
	while (m--)
	{
		long long a = pq.top();
		pq.pop();

		long long b = pq.top();
		pq.pop();

		pq.push(a + b);
		pq.push(a + b);
	}

	while (!pq.empty())
	{
		ans += pq.top();
		pq.pop();
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