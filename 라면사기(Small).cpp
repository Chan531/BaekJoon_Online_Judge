#include <iostream>
#include <algorithm>

using namespace std;

int n, val, ans, arr[10010];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		if (!arr[i])
			continue;

		// b > c라면 우선 5로 지워준다.
		if (arr[i + 1] > arr[i + 2])
		{
			val = min({ arr[i], arr[i + 1], arr[i + 1] - arr[i + 2] });
			arr[i] -= val;
			arr[i + 1] -= val;
			ans += val * 5;
		}

		// 7 -> 5 -> 3순으로 지워준다.
		val = min({ arr[i], arr[i + 1], arr[i + 2] });
		arr[i] -= val;
		arr[i + 1] -= val;
		arr[i + 2] -= val;
		ans += val * 7;

		val = min(arr[i], arr[i + 1]);
		arr[i] -= val;
		arr[i + 1] -= val;
		ans += val * 5;

		ans += arr[i] * 3;
		arr[i] = 0;
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