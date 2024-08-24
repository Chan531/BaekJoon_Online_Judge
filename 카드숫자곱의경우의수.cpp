#include <iostream>

using namespace std;

int n, val = 1, ans;
bool check[5000000];

void input()
{
	cin >> n;
}

void backtrack(int cur, int cnt)
{
	if (cnt == cur)
	{
		if (!check[val])
			ans++;

		check[val] = 1;
		return;
	}

	for (int i = 1; i < 10; i++)
	{
		val *= i;
		backtrack(cur, cnt + 1);
		val /= i;
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
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