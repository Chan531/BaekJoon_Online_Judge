#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s;
	int n;
	while (1)
	{
		cin >> s;
		if (s == "0")
			break;
		while (1)
		{
			n = 0;
			for (int i = 0; i < s.length(); i++)
				n += s[i] - '0';
			if (n < 10)
			{
				cout << n << '\n';
				break;
			}
			s = to_string(n);
		}
	}
	return 0;
}