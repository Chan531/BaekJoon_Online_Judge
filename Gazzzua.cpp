#include <iostream>
#include <algorithm>
#define N 100001

using namespace std;

int n, arr[N], check[N], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = n - 1; i >= 0; i--)
		check[i] = max(arr[i], check[i + 1]);

	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == check[i])
		{
			ans += cnt * arr[i];
			cnt = 0;
		}

		else
		{
			ans -= arr[i];
			cnt++;
		}
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