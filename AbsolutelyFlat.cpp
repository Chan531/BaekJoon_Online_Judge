#include <iostream>

using namespace std;

int arr[4], n, ans;

void input()
{
	for (int i = 0; i < 4; i++) cin >> arr[i];
	cin >> n;
}

void check()
{
	for (int i = 1; i < 4; i++)
	{
		if (arr[i] != arr[i - 1]) return;
		if (i == 3) ans = 1;
	}
}

void solution()
{
	check();

	for (int i = 0; i < 4; i++)
	{
		arr[i] += n;
		check();
		arr[i] -= n;
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