#include <iostream>
#include <stack>
#include <algorithm>
#define p pair<long long, int>

using namespace std;

int n, arr[100000];
long long ben[100000], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	stack<p> st;

	// ÁÂÃø °è»ê
	for (int i = 0; i < n; i++)
	{
		if (st.empty() || st.top().first <= arr[i])
		{
			st.push({ arr[i], i });
			continue;
		}

		while (!st.empty() && st.top().first > arr[i])
		{
			long long val = st.top().first;
			int idx = st.top().second;

			ben[idx] += val * (i - idx);
			st.pop();
		}

		st.push({ arr[i], i });
	}

	while (!st.empty())
	{
		long long val = st.top().first;
		int idx = st.top().second;
		
		ben[idx] += val * (n - idx);
		st.pop();
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (st.empty() || st.top().first <= arr[i])
		{
			st.push({ arr[i], i });
			continue;
		}

		while (!st.empty() && st.top().first > arr[i])
		{
			long long val = st.top().first;
			int idx = st.top().second;

			ben[idx] += val * (idx - i);
			st.pop();
		}

		st.push({ arr[i], i });
	}

	while (!st.empty())
	{
		long long val = st.top().first;
		int idx = st.top().second;

		ben[idx] += val * (idx + 1);
		st.pop();
	}

	for (int i = 0; i < n; i++)
		ans = max(ans, ben[i] - arr[i]);

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