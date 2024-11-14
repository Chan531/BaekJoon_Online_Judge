#include <iostream>

using namespace std;

int n, tar, cnt, map[101][101];
bool check[10101];
string ans = "TRUE";

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) 
		{
			cin >> map[i][j];

			if (!check[map[i][j]])
			{
				check[map[i][j]] = 1;
				cnt++;
			}
		}
	}
}

void solution()
{
	if (cnt != n * n)
		ans = "FALSE";

	tar = n * (n * n + 1) / 2;

	// 가로 확인
	for (int i = 0; i < n; i++)
	{
		int cur = 0;

		for (int j = 0; j < n; j++)
			cur += map[i][j];

		if (cur != tar)
			ans = "FALSE";
	}

	// 세로 확인
	for (int i = 0; i < n; i++)
	{
		int cur = 0;

		for (int j = 0; j < n; j++)
			cur += map[j][i];

		if (cur != tar)
			ans = "FALSE";
	}

	// 대각선 확인
	int cur = 0;

	for (int i = 0; i < n; i++)
		cur += map[i][i];

	if (cur != tar)
		ans = "FALSE";

	cur = 0;

	for (int i = 0; i < n; i++)
		cur += map[i][n - 1 - i];

	if (cur != tar)
		ans = "FALSE";

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