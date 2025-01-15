#include <iostream>

using namespace std;

int n, m, ans;
string s, t;

void input()
{
	cin >> n >> s;
}

void solution()
{
	while (n--)
	{
		cin >> t >> m;

		string temp = "";

		for (int i = 0; i <= t.length(); i++)
		{
			if (i == t.length())
			{
				if (s == temp)
					ans += m;
				break;
			}

			if (t[i] == '_')
			{
				if (s == temp)
				{
					ans += m;
					break;
				}

				temp = "";
				continue;
			}

			temp += t[i];
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