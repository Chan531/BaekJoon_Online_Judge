#include <iostream>

using namespace std;

int n, arr[20], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < 20; i++) cin >> arr[i];
}

void solution()
{
	ans = 0;

	for (int i = 1; i < 20; i++)
		for (int j = 0; j < i; j++)
			if (arr[i] < arr[j])
				ans++;

	cout << n << ' ' << ans << '\n';
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}