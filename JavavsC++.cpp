#include <iostream>
#include <string>

using namespace std;

int java = 0, cplus = 0;
string line, ans = "";

void input()
{
	cin >> line;
}

void solution()
{
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == '_')
		{
			if (java || isupper(line[i + 1]) || line[i + 1] == '_' || i == line.length() - 1 || i == 0)
			{
				cout << "Error!";
				return;
			}
			cplus = 1;
			ans += toupper(line[i + 1]);
			i++;
		}
		else if (isupper(line[i]))
		{
			if (cplus || i == 0)
			{
				cout << "Error!";
				return;
			}
			java = 1;
			ans += '_';
			ans += tolower(line[i]);
		}
		else
			ans += line[i];
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
	solve();

	return 0;
}