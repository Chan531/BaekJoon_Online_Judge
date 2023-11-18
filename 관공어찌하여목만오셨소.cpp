#include <iostream>

using namespace std;

int n;
string s[1010], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> s[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < s[i].length(); j++)
		{
			if (s[i][j] == 'S')
				ans = s[i];
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