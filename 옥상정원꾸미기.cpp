#include <iostream>
#include <stack>
#define p pair<int, int>
#define N 80000

using namespace std;

int n, arr[N];
long long ans;

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
		while (!st.empty() && st.top().first <= arr[i])
		{
			int idx = st.top().second;
			ans += i - idx - 1;
			st.pop();
		}

		st.push({ arr[i], i });
	}

	while (!st.empty())
	{
		int idx = st.top().second;
		ans += n - idx - 1;
		st.pop();
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