#include <iostream>
#include <string>

using namespace std;

string s;
bool check[4][14];

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i < s.length(); i += 3)
	{
		int idx = stoi(s.substr(i + 1, 2));

		if (s[i] == 'P')
		{
			if (check[0][idx])
			{
				cout << "GRESKA";
				return;
			}

			check[0][idx] = 1;
		}

		else if (s[i] == 'K')
		{
			if (check[1][idx])
			{
				cout << "GRESKA";
				return;
			}

			check[1][idx] = 1;
		}

		else if (s[i] == 'H')
		{
			if (check[2][idx])
			{
				cout << "GRESKA";
				return;
			}

			check[2][idx] = 1;
		}

		else if (s[i] == 'T')
		{
			if (check[3][idx])
			{
				cout << "GRESKA";
				return;
			}

			check[3][idx] = 1;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		int cnt = 13;

		for (int j = 1; j < 14; j++)
			if (check[i][j])
				cnt--;

		cout << cnt << ' ';
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