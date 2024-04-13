#include <iostream>

using namespace std;

string s;
int o, e, check[26];

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
		check[s[i] - 'a']++;

	for (int i = 0; i < 26; i++)
	{
		if (!check[i])
			continue;

		check[i] % 2 ? o++ : e++;
	}

	if (o && e)
		cout << "0/1";

	else if (o)
		cout << 1;

	else
		cout << 0;
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