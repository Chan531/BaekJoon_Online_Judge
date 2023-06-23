#include <iostream>
#include <stack>
#include <algorithm>
#define N 101010
#define ll long long
#define p pair<ll, int>

using namespace std;

int n;
ll arr[N], val[N], ans;

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++) 
		cin >> arr[i];
}

void solution()
{
	stack<p> st;

	for (int i = 1; i <= n; i++)
	{
		while (!st.empty() && st.top().first > arr[i])
		{
			int idx = st.top().second;
			val[idx] += st.top().first * (i - idx);
			st.pop();
		}

		st.push({ arr[i], i });
	}

	while (!st.empty())
	{
		int idx = st.top().second;
		val[idx] += st.top().first * (n - idx + 1);
		st.pop();
	}

	for (int i = n; i > 0; i--)
	{
		while (!st.empty() && st.top().first > arr[i])
		{
			int idx = st.top().second;
			val[idx] += st.top().first * (idx - i);
			st.pop();
		}

		st.push({ arr[i], i });
	}

	while (!st.empty())
	{
		int idx = st.top().second;
		val[idx] += st.top().first * idx;
		st.pop();
	}

	for (int i = 1; i <= n; i++)
		ans = max(ans, val[i] - arr[i]);

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