#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

string s;
int ans;

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 1; i < s.length(); i++)
		ans += 9 * pow(10, ((max(0, i) - 1) / 2));

	if (s.length() == 1)
	{
		cout << s;
		return;
	}

	if (s.length() % 2)
	{
		string t = s.substr(0, s.length() / 2);
		string r = t;
		reverse(r.begin(), r.end());
		int f = stoi(t);
		int m = stoi(r);
		int e = stoi(s.substr(s.length() / 2 + 1, s.length() / 2));

		for (int i = pow(10, s.length() / 2 - 1); i <= f; i++)
		{
			if (i == f)
			{
				ans += s[s.length() / 2] - '0';

				if (m <= e)
					ans++;

				break;
			}

			ans += 10;
		}
	}

	else
	{
		string t = s.substr(0, s.length() / 2);
		string r = t;
		reverse(r.begin(), r.end());
		int f = stoi(t);
		int m = stoi(r);
		int e = stoi(s.substr(s.length() / 2, s.length() / 2));

		for (int i = pow(10, s.length() / 2 - 1); i <= f; i++)
		{
			if (i == f && m > e)
				break;

			ans++;
		}
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