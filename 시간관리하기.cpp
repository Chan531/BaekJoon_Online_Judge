#include <iostream>
#include <algorithm>
#define N 1010
#define p pair<int, int>

using namespace std;

int n, ans = -1;
p arr[N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
}

bool cmp(p a, p b)
{
	return a.second > b.second;
}

void solution()
{
	sort(arr, arr + n, cmp);

	int cur = arr[0].second;

	for (int i = 0; i < n; i++)
	{
		if (arr[i].first > arr[i].second)
			break;

		if (cur > arr[i].second)
			cur = arr[i].second;

		cur -= arr[i].first;

		if (i == n - 1)
			ans = cur;
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