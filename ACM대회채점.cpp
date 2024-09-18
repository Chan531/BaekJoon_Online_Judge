#include <iostream>
#include <cstring>

using namespace std;

int n, ans, cnt, arr[26];

void input()
{
	cin >> n;
}

void solution()
{
	char c;
	string s;
	cin >> c >> s;

	if (s == "wrong")
		arr[c - 'A']++;

	else if (s == "right")
	{
		ans += n + arr[c - 'A'] * 20;
		cnt++;
	}
}

void solve()
{
	while (1)
	{
		input();
		if (n == -1)
		{
			cout << cnt << ' ' << ans;
			break;
		}
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