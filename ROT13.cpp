#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i]))
		{
			if (isupper(s[i])) 
			{
				if (s[i] >= 78)
					s[i] -= 13;
				else
					s[i] += 13;
			}
			else
			{
				if (s[i] >= 110)
					s[i] -= 13;
				else
					s[i] += 13;
			}
		}
	}
	cout << s;
	return 0;
}