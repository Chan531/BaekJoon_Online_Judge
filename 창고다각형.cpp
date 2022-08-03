#include <iostream>
#include <algorithm>
#include <stack>
#define p pair<int, int>

using namespace std;

int n, ans;
p arr[1000];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
}

void solution()
{
	sort(arr, arr + n);

	stack<p> st;

	for (int i = 0; i < n; i++)
		if (st.empty() || st.top().second < arr[i].second)
			st.push(arr[i]);

	// °¡Àå Å« ±âµÕ °ªÀ» ÇÏ³ª ´õÇØÁà¾ß ÇÔ
	ans += st.top().second;
	
	// ¿ÞÂÊ ³ÐÀÌ
	while (!st.empty())
	{
		int idx = st.top().first;
		st.pop();

		if (st.empty())
			break;

		ans += st.top().second * (idx - st.top().first);
	}

	for (int i = n - 1; i >= 0; i--)
		if (st.empty() || st.top().second <= arr[i].second)
			st.push(arr[i]);

	// ¿À¸¥ÂÊ ³ÐÀÌ
	while (!st.empty())
	{
		int idx = st.top().first;
		st.pop();

		if (st.empty())
			break;

		ans += st.top().second * (st.top().first - idx);
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