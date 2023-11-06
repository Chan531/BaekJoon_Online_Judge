#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

string s, ans;
int cnt[26], minv;

void input()
{
	getline(cin, s);
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
	{
		if (!isalpha(s[i]))
			continue;

		cnt[tolower(s[i]) - 'a']++;
	}

	minv = 3;

	for (int i = 0; i < 26; i++)
		minv = min(minv, cnt[i]);

	if (minv == 0)
		ans = "Not a pangram";

	else if (minv == 1)
		ans = "Pangram!";

	else if (minv == 2)
		ans = "Double pangram!!";

	else
		ans = "Triple pangram!!!";

	memset(cnt, 0, sizeof(cnt));
}

void solve()
{
	int tc;
	cin >> tc;
	cin.ignore();

	for (int i = 1; i <= tc; i++)
	{
		input();
		solution();
		cout << "Case " << i << ": " << ans << '\n';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}