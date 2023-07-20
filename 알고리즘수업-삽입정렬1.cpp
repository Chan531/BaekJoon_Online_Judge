#include <iostream>

using namespace std;

int n, k, arr[10000], ans = -1;

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> arr[i];
}

void solution()
{
	int cnt = 0;

	for (int i = 1; i < n; i++)
	{
		int num = arr[i];
		int idx = i;

		while (idx && num < arr[idx - 1])
		{
			arr[idx] = arr[idx - 1];
			cnt++;

			if (cnt == k)
				ans = arr[idx];

			idx--;
		}

		if (idx != i)
		{
			arr[idx] = num;
			cnt++;

			if (cnt == k)
				ans = arr[idx];
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

	solve();
	return 0;
}