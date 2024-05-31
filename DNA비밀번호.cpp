#include <iostream>

using namespace std;

int n, m, arr[26], cnt[26], ans;
string s;

void input()
{
	cin >> n >> m >> s >> arr[0] >> arr[2] >> arr[6] >> arr[19];
}

void check()
{
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] < arr[i])
			break;

		if (i == 25)
			ans++;
	}
}

void solution()
{
	for (int i = 0; i < m; i++)
		cnt[s[i] - 'A']++;

	check();

	for (int i = m; i < n; i++)
	{
		cnt[s[i - m] - 'A']--;
		cnt[s[i] - 'A']++;
		check();
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