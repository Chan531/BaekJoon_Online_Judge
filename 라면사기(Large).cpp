#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int n;
ll b, c, val, ans, arr[1001010];

void input()
{
	cin >> n >> b >> c;

	for (int i = 0; i < n; i++) cin >> arr[i];
}

void solution()
{
	if (b <= c)
	{
		for (int i = 0; i < n; i++)
			ans += arr[i] * b;

		cout << ans;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!arr[i])
			continue;

		// arr[i + 1] > arr[i + 2]라면 우선 b + c로 지워준다.
		if (arr[i + 1] > arr[i + 2])
		{
			val = min({ arr[i], arr[i + 1], arr[i + 1] - arr[i + 2] });
			arr[i] -= val;
			arr[i + 1] -= val;
			ans += val * (b + c);
		}

		// b + 2 * c -> b + c -> b순으로 지워준다.
		val = min({ arr[i], arr[i + 1], arr[i + 2] });
		arr[i] -= val;
		arr[i + 1] -= val;
		arr[i + 2] -= val;
		ans += val * (b + 2 * c);

		val = min(arr[i], arr[i + 1]);
		arr[i] -= val;
		arr[i + 1] -= val;
		ans += val * (b + c);

		ans += arr[i] * b;
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