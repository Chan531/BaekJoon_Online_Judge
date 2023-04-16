#include <iostream>
#include <cstring>

using namespace std;

string s;
int cnt[26];

void input()
{
	cin >> s;
}

void solution()
{
	memset(cnt, 0, sizeof(cnt));

	for (int i = 0; i < s.length(); i++)
	{
		if (++cnt[s[i] - 'A'] == 3)
		{
			if (++i < s.length() && s[i - 1] == s[i])
			{
				cnt[s[i] - 'A'] = 0;
				continue;
			}

			else
			{
				cout << "FAKE\n";
				return;
			}
		}
	}

	cout << "OK\n";
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}