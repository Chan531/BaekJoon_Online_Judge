#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int count = 0;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'U' && count == 0)
			count++;

		if (s[i] == 'C' && (count == 1 || count == 3))
			count++;

		if (s[i] == 'P' && count == 2)
			count++;
	}
	count == 4 ? cout << "I love UCPC" : cout << "I hate UCPC";
	return 0;
}