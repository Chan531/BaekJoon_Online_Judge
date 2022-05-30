#include <iostream>

using namespace std;

string str;
char c;
int q, l, r, alp[200000][26];

void input()
{
	cin >> str >> q;
}

void solution()
{
	alp[0][str[0] - 'a'] = 1;

	for (int i = 1; i < str.length(); i++)
	{
		alp[i][str[i] - 'a']++;

		for (int j = 0; j < 26; j++)
			alp[i][j] += alp[i - 1][j];
	}

	while (q--)
	{
		cin >> c >> l >> r;

		if (!l)
			cout << alp[r][c - 'a'] << '\n';

		else
			cout << alp[r][c - 'a'] - alp[l - 1][c - 'a'] << '\n';
	}
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