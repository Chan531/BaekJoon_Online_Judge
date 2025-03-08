#include <iostream>
#define p pair<int, int>

using namespace std;

int w, n, cw, ans;
p arr[1010];

void input()
{
	cin >> w >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i].first >> arr[i].second;
}

void solution()
{
	cw = w;

	for (int i = 1; i <= n; i++)
	{
		ans += arr[i].first - arr[i - 1].first;

		if (cw < arr[i].second)
		{
			ans += arr[i].first * 2;
			cw = w;
		}

		cw -= arr[i].second;

		if (i == n && cw != w)
		{
			ans += arr[i].first;
			break;
		}

		if (!cw)
		{
			ans += arr[i].first * 2;
			cw = w;
		}
	}

	cout << ans << '\n';
	ans = 0;
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}