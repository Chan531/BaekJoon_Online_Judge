#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s, sh;
	int count = 0;
	getline(cin, s);
	getline(cin, sh);
	if (sh.length() > s.length())
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i <= s.length() - sh.length(); i++)
	{
		if (s.substr(i, sh.length()) == sh)
		{
			count++;
			i += sh.length() - 1;
		}
	}
	cout << count;
	return 0;
}