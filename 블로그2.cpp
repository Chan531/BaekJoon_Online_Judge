#include <iostream>

using namespace std;

int n, b, r;
string s;

void input()
{
	cin >> n >> s;
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'B')
		{
			while (i < n && s[i] == 'B')
			{
				i++;
			}

			i--;
			b++;
			continue;
		}

		if (s[i] == 'R')
		{
			while (i < n && s[i] == 'R')
			{
				i++;
			}

			i--;
			r++;
		}
	}

	b > r ? cout << r + 1 : cout << b + 1;
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