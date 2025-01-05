#include <iostream>

using namespace std;

int n, m, val, ans;

void input()
{
	cin >> n;
}

void solution()
{
	m = n;

	for (int i = 0; i < 8; i++)
		if (m < 210) m++;

	if (val <= m) val = m, ans = 1;
	m = n;

	for (int i = 0; i < 4; i++)
		if (m < 220) m++;

	if (val <= m) val = m, ans = 2;
	m = n;

	for (int i = 0; i < 2; i++)
		if (m < 230) m++;

	if (val <= m) val = m, ans = 3;
	m = n;

	if (val <= m + 1) val = m + 1, ans = 4;

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