#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string line;
	while (getline(cin, line))
	{
		if (line == "#")
			break;
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == ' ')
				cout << "%20";
			else if (line[i] == '!')
				cout << "%21";
			else if (line[i] == '$')
				cout << "%24";
			else if (line[i] == '%')
				cout << "%25";
			else if (line[i] == '(')
				cout << "%28";
			else if (line[i] == ')')
				cout << "%29";
			else if (line[i] == '*')
				cout << "%2a";
			else cout << line[i];
		}
		cout << '\n';
	}
	return 0;
}