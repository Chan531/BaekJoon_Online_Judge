#include <iostream>
#include <stack>
#define N 1000100
#define p pair<int, int>

using namespace std;

int n, arr[N], ans[N];
stack<p> st;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		while (!st.empty() && st.top().first < arr[i])
		{
			ans[st.top().second] = arr[i];
			st.pop();
		}

		st.push({ arr[i], i });
	}

	for (int i = 0; i < n; i++)
	{
		if (!ans[i])
			ans[i] = -1;

		cout << ans[i] << ' ';
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