#include <iostream>
#include <algorithm>
#include <cmath>
#define N 10
#define p pair<int, int>

using namespace std;

int n, ans = 1e9;
p arr[N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
}

void solution()
{
	for (int i = 1; i < (1 << n); i++)
	{
		int a = 1, b = 0;

		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				a *= arr[j].first;
				b += arr[j].second;
			}
		}

		ans = min(ans, abs(a - b));
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