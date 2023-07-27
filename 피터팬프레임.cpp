#include <iostream>
#include <algorithm>

using namespace std;

string s;
char ans[5][75];

void input()
{
	cin >> s;
}

void frame(int idx, char c)
{
	ans[0][idx + 2] = c;
	ans[1][idx + 1] = c;
	ans[1][idx + 3] = c;
	ans[2][idx] = c;
	ans[2][idx + 2] = s[idx / 5];
	ans[2][idx + 4] = c;
	ans[3][idx + 1] = c;
	ans[3][idx + 3] = c;
	ans[4][idx + 2] = c;
}

void solution()
{
	fill(&ans[0][0], &ans[4][75], '.');

	for (int i = 0; i < s.length(); i++)
		i % 3 == 2 ? frame(i * 5, '*') : frame(i * 5, '#');

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < s.length() * 5; j++)
		{
			if (j % 5 == 4 && (j + 1) % 15 != 0 && j != s.length() * 5 - 1)
				continue;

			if (j != 0 && j % 15 == 0)
				continue;

			cout << ans[i][j];
		}

		cout << '\n';
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