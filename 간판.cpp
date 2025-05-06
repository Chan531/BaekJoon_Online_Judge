#include <iostream>

using namespace std;

int n, ans;
string s;

void input()
{
	cin >> n >> s;
}

void solution()
{
	while (n--)
	{
		string t;
		cin >> t;
		bool flag = 0;

		for (int i = 1; ; i++)
		{
			if (i * (s.length() - 1) >= t.length()) break;

			for (int j = 0; j < t.length(); j++)
			{
				if (j + i * (s.length() - 1) >= t.length()) break;

				string cur = "";

				for (int k = 0; k < s.length(); k++)
					cur += t[j + k * i];

				if (cur == s)
				{
					flag = 1;
					break;
				}
			}

			if (flag)
			{
				ans++;
				break;
			}
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