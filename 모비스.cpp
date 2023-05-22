#include <iostream>

using namespace std;

int cnt;
string s;
bool alpha[26];

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'M' || s[i] == 'O' || s[i] == 'B' || s[i] == 'I' || s[i] == 'S') 
		{
			if (!alpha[s[i] - 'A'])
				cnt++;

			alpha[s[i] - 'A'] = 1;
		}
	}

	cnt == 5 ? cout << "YES" : cout << "NO";
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