#include <iostream>
#include <cstring>

using namespace std;

int n, arr[1010], ans, val, cnt;
bool check[1010];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];
}

void dfs(int n)
{
	if (check[n]) return;

	check[n] = 1;
	cnt++;
	dfs(arr[n]);
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		dfs(i);
		if (val < cnt)
		{
			ans = i;
			val = cnt;
		}
		memset(check, 0, sizeof(check));
		cnt = 0;
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