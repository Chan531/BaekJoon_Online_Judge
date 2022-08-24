#include <iostream>
#include <algorithm>

using namespace std;

int n, ans, arr[1000];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n, greater<int>());

	for (int i = n; i >= 0; i--)
	{
		int cnt = 0;

		for (int j = 0; j < n; j++)
			if (i <= arr[j])
				cnt++;

		if (cnt >= i)
		{
			ans = i;
			break;
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