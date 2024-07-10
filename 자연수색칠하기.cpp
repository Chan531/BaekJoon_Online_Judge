#include <iostream>
#define N 505050

using namespace std;

int n, ans, arr[N];

void input()
{
	cin >> n;
}

void solution()
{
	arr[1] = 1;
	ans = 2;

	for (int i = 2; i <= n; i++)
	{
		if (arr[i]) continue;

		arr[i] = ans;

		for (int j = i * 2; j <= n; j += i)
			arr[j] = ans;

		ans++;
	}

	cout << ans - 1 << '\n';

	for (int i = 1; i <= n; i++)
		cout << arr[i] << ' ';
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