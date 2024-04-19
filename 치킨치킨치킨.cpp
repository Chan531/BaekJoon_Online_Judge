#include <iostream>
#include <algorithm>
#define N 33

using namespace std;

int n, m, k, ans, arr[N][N], c[3];
bool check[N];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
}

int cal()
{
	int ret = 0;

	for (int i = 0; i < n; i++)
	{
		int temp = 0;

		for (int j = 0; j < k; j++)
			temp = max(temp, arr[i][c[j]]);

		ret += temp;
	}

	return ret;
}

void backtrack(int idx, int cnt)
{
	if (cnt == k)
	{
		ans = max(ans, cal());
		return;
	}

	for (int i = idx; i < m; i++)
	{
		check[i] = 1;
		c[cnt] = i;
		backtrack(idx + 1, cnt + 1);
		check[i] = 0;
	}
}

void solution()
{
	k = min(n, 3);

	for (int i = 0; i <= m - k; i++)
		backtrack(i, 0);

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