#include <iostream>

using namespace std;

int a[3], b[3], ans;

void input()
{
	for (int i = 0; i < 3; i++)
		cin >> a[i];

	for (int i = 0; i < 3; i++)
		cin >> b[i];
}

void solution()
{
	for (int i = 0; i < 3; i++)
		if (b[i] - a[i] > 0)
			ans += b[i] - a[i];

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