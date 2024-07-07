#include <iostream>
#include <algorithm>
#define N 101

using namespace std;

int n, arr[8], bt[8], ans;
bool check[8], line[N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void backtrack(int cnt, int cur)
{
	if (cnt == n)
	{
		int temp = 0;

		for (int i = 0; i <= N / 2; i++)
			if (line[i] && line[i + 50])
				temp++;

		ans = max(ans, temp);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (check[i]) continue;

		line[cur + arr[i]] = 1;
		check[i] = 1;
		backtrack(cnt + 1, cur + arr[i]);
		check[i] = 0;
		line[cur + arr[i]] = 0;
	}
}

void solution()
{
	backtrack(0, 0);
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