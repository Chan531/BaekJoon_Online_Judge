#include <iostream>

using namespace std;

int main(void)
{
	int n, sl;
	string s;
	cin >> n >> s;
	sl = s.length() - 1;
	for (int i = 0; i <= n / 2; i++)
	{
		if (i == sl - i)
		{
			if (s[i] == '?')
				s[i] = 'a';
			continue;
		}
		if (s[i] == '?' && isalpha(s[sl - i]))
			s[i] = s[sl - i];
		else if (isalpha(s[i]) && s[sl - i] == '?')
			s[sl - i] = s[i];
		else if (s[i] == '?' && s[sl - i] == '?')
		{
			s[i] = 'a';
			s[sl - i] = 'a';
		}
	}
	cout << s;
}