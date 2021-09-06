#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int j = 0, i = 0;
	string s;
	cin >> s;
	for (int k = 0; k < s.length(); k++)
	{
		if (s[k] == 'J')
		{
			if (s.substr(k, 3) == "JOI")
				j++;
		}
		if (s[k] == 'I')
		{
			if (s.substr(k, 3) == "IOI")
				i++;
		}
	}
	cout << j << '\n' << i;
	return 0;
}