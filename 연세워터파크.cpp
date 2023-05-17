#include <iostream>
#include <algorithm>
#include <deque>
#define N 100010

using namespace std;

int n, d;
long long arr[N], dp[N], ans = -1e9;

deque<int> dq;

void input()
{
	cin >> n >> d;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		while (!dq.empty() && dq.front() < i - d)
			dq.pop_front();

		if (dq.empty() || dp[dq.front()] < 0)
			dp[i] = arr[i];

		else
			dp[i] = dp[dq.front()] + arr[i];

		// 이렇게 한 줄로도 가능
		// dp[i] = (dq.empty() || dp[dq.front()] <= 0 ? 0 : dp[dq.front()]) + arr[i];

		ans = max(ans, dp[i]);

		while (!dq.empty() && dp[dq.back()] <= dp[i])
			dq.pop_back();

		dq.push_back(i);
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

	solve();
	return 0;
}