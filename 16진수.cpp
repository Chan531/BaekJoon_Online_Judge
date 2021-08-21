#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	string s;
	int n = 0;
	cin >> s;
	for (int i = 1; i <= s.length(); i++)
	{
		if (isalpha(s[i - 1]))
			n += (s[i - 1] - 55) * pow(16, s.length() - i);
		else
			n += (s[i - 1] - '0') * pow(16, s.length() - i);
	}
	cout << n;
	return 0;
}