#include <iostream>

using namespace std;

int n, d;

void input()
{
	cin >> n >> d;
}

void solution()
{
	while (n--)
	{
		string s, ans;
		cin >> s;
		ans = "";

		for (int i = 0; i < s.length(); i++)
		{
			if (d == 1)
			{
				if (s[i] == 'd')
					ans += 'q';

				else if (s[i] == 'b')
					ans += 'p';

				else if (s[i] == 'q')
					ans += 'd';

				else
					ans += 'b';
			}

			else if (d == 2)
			{
				if (s[i] == 'd')
					ans += 'b';

				else if (s[i] == 'b')
					ans += 'd';

				else if (s[i] == 'q')
					ans += 'p';

				else
					ans += 'q';
			}
		}

		cout << ans << '\n';
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