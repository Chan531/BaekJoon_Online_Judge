#include <iostream>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	int n = 0, sl = s.length();
	for (int i = 0; i < sl; i++)
	{
		if (i < sl / 2)
			n -= s[i] - '0';
		else
			n += s[i] - '0';
	}
	n ? cout << "READY" : cout << "LUCKY";
	return 0;
}