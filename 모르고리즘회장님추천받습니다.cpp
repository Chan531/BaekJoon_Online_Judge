#include <iostream>
#include <algorithm>
#define p pair<int, string>

using namespace std;

int n;
p arr[101010];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].second >> arr[i].first;
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
	cout << arr[0].second;
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