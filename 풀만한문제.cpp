#include <iostream>
#include <string>

using namespace std;

int j, n, ans;

void input()
{
	cin >> j >> n;
}

void solution()
{
	cin.ignore();

	while (n--)
	{
		int val = 0;
		string s;
		getline(cin, s);

		for (int i = 0; i < s.length(); i++)
		{
			if (isblank(s[i]))
				val++;

			else if (isdigit(s[i]))
				val += 2;

			else
			{
				if (isupper(s[i]))
					val += 4;
				else
					val += 2;
			}
		}

		if (val <= j)
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