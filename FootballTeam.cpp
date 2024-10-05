#include <iostream>
#include <string>

using namespace std;

void input()
{

}

void solution()
{
	while (!cin.eof())
	{
		string s;
		getline(cin, s);
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'e') s[i] = 'i';
			else if (s[i] == 'i') s[i] = 'e';
			else if (s[i] == 'E') s[i] = 'I';
			else if (s[i] == 'I') s[i] = 'E';
		}
		cout << s << '\n';
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