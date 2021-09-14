#include <iostream>

using namespace std;

int main(void)
{
	string s;
	int a = 0, b = 0, aa = 0, bb = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'A')
			a++;
		else if (s[i] == 'B')
			b++;
		if (a == 21)
		{
			cout << a << '-' << b << '\n';
			a = 0;
			b = 0;
			aa++;
		}
		if (b == 21)
		{
			cout << a << '-' << b << '\n';
			a = 0;
			b = 0;
			bb++;
		}
	}
	aa >> bb ? cout << 'A' : cout << 'B';
	return 0;
}