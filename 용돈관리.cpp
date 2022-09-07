#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[100000], ans = 1e9;

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	int start = 0, end = 1e9;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		int budget = mid;
		int cnt = m - 1;                   // 첫 날 돈 뽑는 거도 고려해야 함!

		for (int i = 0; i < n; i++)
		{
			if (mid < arr[i])              // k >= arr[i]의 max값을 만족해야 함
			{
				cnt = -1;
				break;
			}

			if (budget < arr[i])
			{
				budget = mid;
				cnt--;
			}

			budget -= arr[i];
		}

		if (cnt >= 0)
		{
			ans = min(ans, mid);
			end = mid - 1;
		}

		else
			start = mid + 1;
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