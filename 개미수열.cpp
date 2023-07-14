#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string s = "1";
char c = '0';

void input()
{
	cin >> n;
}

void solution()
{/*
	if (n <= 2)
		cout << 1;

	else if (n <= 5)
		cout << 2;

	else 
		cout << 3;
	*/
	for (int i = 2; i <= n; i++)
	{
		int idx = 0;
		string temp = "";

		while (idx < s.length())
		{
			int cnt = 1;
			temp += s[idx++];

			while (idx < s.length() && s[idx - 1] == s[idx])
			{
				cnt++;
				idx++;
			}

			temp += to_string(cnt);
		}

		s = temp;
	}

	for (auto i : s)
		c = max(c, i);

	cout << s << '\n';

	cout << c;
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