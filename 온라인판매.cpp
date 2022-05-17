#include <iostream>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, m, arr[1000];
p ans;

void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + m);

	for (int i = 0; i < m; i++)
	{
		int price = arr[i];

		if (price * min(m - i, n) > ans.second)
		{
			ans.first = price;
			ans.second = price * min(m - i, n);
		}
	}

	cout << ans.first << ' ' << ans.second;
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