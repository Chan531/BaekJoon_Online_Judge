#include <iostream>
#include <string>

using namespace std;

int a, b;
string s;
char c[5] = { 'a', 'e', 'i', 'o', 'u' };

void input()
{
	getline(cin, s);
}

void solution()
{
	a = 0, b = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (!isalpha(s[i]))
			continue;
		
		for (int j = 0; j < 5; j++)
		{
			if (c[j] == tolower(s[i]))
			{
				b++;
				break;
			}

			if (j == 4)
				a++;
		}
	}

	cout << a << ' ' << b << '\n';
}

void solve()
{
	int testcase;
	cin >> testcase;
	cin.ignore();

	while (testcase--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}