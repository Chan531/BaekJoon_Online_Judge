#include <iostream>

using namespace std;

int n, cnt, arr[1010], ans;
string s;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		long long m;
		cin >> s >> m;

		if (s == "jinju") ans = m;

		if (m > 1000) cnt++;
		else arr[m]++;
	}
}

void solution()
{
	for (int i = ans + 1; i < 1010; i++)
		cnt += arr[i];

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