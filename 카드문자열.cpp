#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int t, n;
	string s;
	char c;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		s = "";
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> c;
			if (j == 0)
				s += c;
			else if (s[0] >= c)
			{
				string t = s;
				s = c;
				s += t;
			}
			else
				s += c;
		}
		cout << s << '\n';
	}
	return 0;
}