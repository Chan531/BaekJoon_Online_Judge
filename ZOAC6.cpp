#include <iostream>
#include <string>

using namespace std;

int n, ans;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		string s;
		cin >> s;

		for (int i = 0; i < s.length() - 1; i++)
		{
			string str = s.substr(i, 2);

			if (str == "01" || str == "OI")
			{
				ans++;
				break;
			}
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