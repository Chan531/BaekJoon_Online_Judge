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
	cin.ignore();

	while (n--)
	{
		string s;
		getline(cin, s);

		int g = 0, b = 0;

		for (int i = 0; i < s.length(); i++)
		{
			if (isalpha(s[i]))
			{
				if (s[i] == 'g' || s[i] == 'G')
					g++;

				else if (s[i] == 'b' || s[i] == 'B')
					b++;
			}
		}

		if (g > b)
			cout << s << " is GOOD\n";

		else if (g < b)
			cout << s << " is A BADDY\n";

		else
			cout << s << " is NEUTRAL\n";
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