#include <iostream>
#include <algorithm>

using namespace std;

int n, d, k, c;
int arr[33000], check[3001];

void input()
{
	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	check[c] = 1;
	int ans = 1;
	int cnt = 1;
	int idx = 0;

	// 마지막과 첫번째도 이어져야 함...
	for (int i = n; i < n + k; i++)
		arr[i] = arr[idx++];

	idx = 0;

	for (int i = 0; i < n + k; i++)
	{
		if (!check[arr[i]])
			cnt++;

		check[arr[i]]++;

		if (i < k - 1)
			continue;

		ans = max(ans, cnt);

		if (check[arr[idx]] == 1)
			cnt--;

		check[arr[idx++]]--;
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