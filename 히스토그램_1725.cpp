#include <iostream>
#include <stack>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, arr[100000], box[100000], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	stack<p> st;
	st.push({ -1 , 0 });

	for (int i = 0; i < n; i++)
	{
		while (st.top().first > arr[i])
		{
			int cnt = i - st.top().second;
			box[st.top().second] += st.top().first * cnt;
			st.pop();
		}

		st.push({ arr[i], i });
	}

	int cnt = st.top().second;

	while (st.top().first != -1)
	{
		int val = st.top().first;

		box[st.top().second] += val * (cnt - st.top().second + 1);
		st.pop();
	}

	for (int i = n - 1; i >= 0; i--)
	{
		while (st.top().first > arr[i])
		{
			int cnt = st.top().second - i;
			box[st.top().second] += st.top().first * cnt;
			st.pop();
		}

		st.push({ arr[i], i });
	}

	cnt = st.top().second;

	while (st.top().first != -1)
	{
		int val = st.top().first;

		box[st.top().second] += val * (st.top().second - cnt + 1);
		st.pop();
	}

	for (int i = 0; i < n; i++)
		ans = max(ans, box[i] - arr[i]);

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