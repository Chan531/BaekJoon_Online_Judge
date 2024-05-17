#include <iostream>

using namespace std;

string s;
bool check[26];

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
		check[s[i] - 'A'] = 1;

	for (int i = 0; i < 26; i++)
	{
		if (check[i])
			continue;

		cout << (char) (i + 'A');
		break;
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

	solve();
	return 0;
}