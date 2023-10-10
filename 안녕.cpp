#include <iostream>
#include <algorithm>
#define N 22

using namespace std;

int n, h[N], p[N], ans;
bool check[N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> h[i];

	for (int i = 0; i < n; i++)
		cin >> p[i];
}

void backtrack(int idx, int hp, int val)
{
	if (hp <= 0)
		return;

	ans = max(ans, val);

	for (int i = idx + 1; i < n; i++)
	{
		if (check[i])
			continue;

		check[i] = 1;
		backtrack(i, hp - h[i], val + p[i]);
		check[i] = 0;
	}
}

void solution()
{
	backtrack(-1, 100, 0);
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