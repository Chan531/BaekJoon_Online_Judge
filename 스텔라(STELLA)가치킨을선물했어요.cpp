#include <iostream>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, ans;
p arr[66];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
}

bool cmp(p a, p b)
{
	if (a.first == b.first)
		return a.second < b.second;

	return a.first > b.first;
}

void solution()
{
	sort(arr, arr + n, cmp);

	for (int i = 5; i < n; i++)
		if (arr[i].first == arr[4].first)
			ans++;

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