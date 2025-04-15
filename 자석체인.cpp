#include <iostream>

using namespace std;

int n;
string s, ans = "Yes";

void input()
{
	cin >> n >> s;
}

void solution()
{
	for (int i = 2; i < 2 * n; i += 2)
	{
		if (s[i] != s[i - 2])
		{
			ans = "No";
			break;
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