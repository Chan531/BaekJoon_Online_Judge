#include <iostream>
#include <cmath>
#define N 36

using namespace std;

string s[N + 1], ans = "Valid";
bool map[6][6];

void input()
{
	for (int i = 0; i < 36; i++) cin >> s[i];
}

void solution()
{
	s[N] = s[0];

	for (int i = 0; i < N; i++)
	{
		int x = s[i][0] - 'A';
		int y = s[i][1] - '1';
		int nx = s[i + 1][0] - 'A';
		int ny = s[i + 1][1] - '1';
		int val = abs((x - nx) * (y - ny));

		if (map[x][y] || val != 2)
		{
			ans = "Invalid";
			break;
		}

		map[x][y] = 1;
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