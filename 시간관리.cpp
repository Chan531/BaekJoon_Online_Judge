#include <iostream>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n;
p arr[1010];

bool cmp(p a, p b)
{
	return a.first > b.first;
}

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].second >> arr[i].first;
}

void solution()
{
	sort(arr, arr + n, cmp);

	int ans = arr[0].first;

	for (int i = 0; i < n; i++)
	{
		if (ans > arr[i].first)
			ans = arr[i].first;

		ans -= arr[i].second;
	}

	cout << max(ans, -1);
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