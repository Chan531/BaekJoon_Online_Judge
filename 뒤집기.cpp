#include <iostream>

using namespace std;

int main(void)
{
	int one = 0, zero = 0;
	string s;
	cin >> s;
	s[0] == '0' ? zero++ : one++;
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] != s[i - 1])
			s[i] == '0' ? zero++ : one++;
	}
	zero > one ? cout << one : cout << zero;
	return 0;
}