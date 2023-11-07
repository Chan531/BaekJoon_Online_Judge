#include <iostream>

using namespace std;

int n, arr[1010][5], ans, maxv;

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];
}

void backtrack(int num, int idx, int val, int cnt)
{
	if (cnt == 3)
	{
		if (maxv <= val % 10)
		{
			maxv = val % 10;
			ans = num;
		}

		return;
	}

	for (int i = idx + 1; i < 5; i++)
		backtrack(num, i, val + arr[num][i], cnt + 1);
}

void solution()
{
	for (int i = 1; i <= n; i++)
		backtrack(i, -1, 0, 0);

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