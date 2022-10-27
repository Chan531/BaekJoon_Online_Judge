#include <iostream>
#include <stack>
#include <algorithm>
#define p pair<long long, int>

using namespace std;

int n;
long long arr[1000000], sum[1000000], ans;

void input()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	stack<p> st;
	
	for (int i = 0; i < n; i++)
	{
		while (!st.empty() && st.top().first > arr[i])
		{
			long long val = st.top().first;
			int idx = st.top().second;

			sum[idx] += val * (i - idx);
			st.pop();
		}

		st.push({ arr[i], i });
	}

	while (!st.empty())
	{
		long long val = st.top().first;
		int idx = st.top().second;

		sum[idx] += val * (n - idx);
		st.pop();
	}

	for (int i = n - 1; i >= 0; i--)
	{
		while (!st.empty() && st.top().first > arr[i])
		{
			long long val = st.top().first;
			int idx = st.top().second;

			sum[idx] += val * (idx - i);
			st.pop();
		}

		st.push({ arr[i], i });
	}

	while (!st.empty())
	{
		long long val = st.top().first;
		int idx = st.top().second;

		sum[idx] += val * (idx + 1);
		st.pop();
	}

	for (int i = 0; i < n; i++)
		ans = max(ans, sum[i] - arr[i]);

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