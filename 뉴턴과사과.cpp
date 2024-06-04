#include <iostream>

using namespace std;

int arr[5], x, y, r, ans;

void input()
{
	for (int i = 1; i <= 4; i++)
		cin >> arr[i];

	cin >> x >> y >> r;
}

void solution()
{
	for (int i = 1; i <= 4; i++)
		if (arr[i] == x)
			ans = i;

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