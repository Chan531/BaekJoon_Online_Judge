#include <iostream>
#include <algorithm>

using namespace std;

int n, x, arr[250000], ans, cnt;

void input()
{
	cin >> n >> x;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	int sum = 0, idx = 0;

	for (int i = 0; i < x; i++)
		sum += arr[i];

	if (sum > 0)
	{
		ans = sum;
		cnt = 1;
	}

	for (int i = x; i < n; i++)
	{
		sum += arr[i] - arr[idx++];

		if (sum > ans)
		{
			ans = sum;
			cnt = 1;
		}

		else if (sum == ans)
			cnt++;
	}

	ans ? cout << ans << '\n' << cnt : cout << "SAD";
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