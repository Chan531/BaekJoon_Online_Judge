#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[50500], ans;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int m;
		cin >> m;
		arr[m]++;
		ans = max(ans, arr[m]);
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