#include <iostream>
#include <string>

using namespace std;

string s;

void input()
{
	getline(cin, s);
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
	{
		if (i <= s.length() - 6)
		{
			string str = s.substr(i, 6);

			if (str == "social")
			{
				cout << "digital humanities";
				break;
			}

			if (str == "public")
			{
				cout << "public bigdata";
				break;
			}
		}

		if (i <= s.length() - 7)
		{
			string str = s.substr(i, 7);

			if (str == "history")
			{
				cout << "digital humanities";
				break;
			}

			if (str == "bigdata" || str == "society")
			{
				cout << "public bigdata";
				break;
			}
		}

		if (i <= s.length() - 8)
		{
			string str = s.substr(i, 8);

			if (str == "language" || str == "literacy")
			{
				cout << "digital humanities";
				break;
			}
		}
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