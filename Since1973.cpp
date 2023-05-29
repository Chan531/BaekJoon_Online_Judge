#include <iostream>
#include <string>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	int ans = 1;

	for (int i = 1; i <= n; i++)
	{
		if (i == n)
			break;

		string s = to_string(i);

		for (int i = 0; i < s.length() - 1; i++)
		{
			if (s.substr(i, 2) == "50")
			{
				ans++;
				break;
			}
		}

		ans++;
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