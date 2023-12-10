#include <iostream>
#include <algorithm>

using namespace std;

string s;
int q[4], cur, ans;

void input()
{
	cin >> s;
}

bool check()
{
	for (int i = 0; i < 4; i++)
		if (q[i])
			return false;

	return true;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'q')
		{
			q[0]++;
			cur++;
			ans = max(ans, cur);
		}

		else if (s[i] == 'u')
		{
			if (q[0] == 0)
			{
				cout << -1;
				return;
			}

			q[0]--;
			q[1]++;
		}

		else if (s[i] == 'a')
		{
			if (q[1] == 0)
			{
				cout << -1;
				return;
			}

			q[1]--;
			q[2]++;
		}

		else if (s[i] == 'c')
		{
			if (q[2] == 0)
			{
				cout << -1;
				return;
			}

			q[2]--;
			q[3]++;
		}

		else
		{
			if (q[3] == 0)
			{
				cout << -1;
				return;
			}

			q[3]--;
			cur--;
		}
	}

	check() ? cout << ans : cout << -1;
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