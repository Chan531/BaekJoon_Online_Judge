#include <iostream>

using namespace std;

int n, cnt, ans, arr[1010];
string s;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s >> arr[i];

		if (s == "jinju") ans = arr[i];
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
		if (arr[i] > ans)
			cnt++;

	cout << ans << '\n' << cnt;
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