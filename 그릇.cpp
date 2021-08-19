#include <iostream>

using namespace std;

int main(void)
{
	int k = 0, h = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (k == 0 && s[i] == '(')
		{
			k = 1;
			h += 10;
		}
		else if (k == 1 && s[i] == '(')
			h += 5;
		else if (k == 1 && s[i] == ')')
		{
			k = 0;
			h += 10;
		}
		else if (i == 0)
			h += 10;
		else
			h += 5;
	}
	cout << h;
	return 0;
}