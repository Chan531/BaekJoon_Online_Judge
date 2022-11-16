#include <iostream>
#include <algorithm>

using namespace std;

string s;
int alpha[26];

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
	{
		if (isupper(s[i]))
			alpha[s[i] - 'A']++;

		else
			alpha[s[i] - 'a']++;
	}

	int maxnum = *max_element(alpha, alpha + 26);
	int cnt = count(alpha, alpha + 26, maxnum);
	char ans = '?';

	for (int i = 0; i < 26; i++)
		if (maxnum == alpha[i] && cnt == 1)
			ans = i + 'A';

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
	cout.tie(NULL);

	solve();
	return 0;
}