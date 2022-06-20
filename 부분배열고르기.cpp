#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int n;
long long arr[100001], prefixsumleft[100001], prefixsumright[100002], score[100001], ans;

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		prefixsumleft[i] = arr[i] + prefixsumleft[i - 1];
	}
}

void solution()
{
	for (int i = n; i > 0; i--)
		prefixsumright[i] = arr[i] + prefixsumright[i + 1];

	stack<int> st;

	for (int i = 1; i <= n; i++)
	{
		while (!st.empty() && arr[st.top()] > arr[i])
		{
			int idx = st.top();
			score[idx] += arr[idx] * (prefixsumleft[i - 1] - prefixsumleft[idx - 1]);
			st.pop();
		}

		st.push(i);
	}

	while (!st.empty())
	{
		int idx = st.top();
		score[idx] += arr[idx] * (prefixsumleft[n] - prefixsumleft[idx - 1]);
		st.pop();
	}

	for (int i = n; i > 0; i--)
	{
		while (!st.empty() && arr[st.top()] > arr[i])
		{
			int idx = st.top();
			score[idx] += arr[idx] * (prefixsumright[i + 1] - prefixsumright[idx + 1]);
			st.pop();
		}

		st.push(i);
	}

	while (!st.empty())
	{
		int idx = st.top();
		score[idx] += arr[idx] * (prefixsumright[1] - prefixsumright[idx + 1]);
		st.pop();
	}

	for (int i = 1; i <= n; i++)
		ans = max(ans, score[i] - arr[i] * arr[i]);

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