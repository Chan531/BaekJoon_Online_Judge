#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	int t;
	double n;
	string s, sn;
	char c;
	cin >> t;
	cin.ignore();
	cout << fixed;
	cout.precision(2);
	for (int i = 0; i < t; i++)
	{
		vector<char> v;
		getline(cin, s);
		sn = "";
		for (int j = 0; j < s.length(); j++)
		{
			if (isdigit(s[j]))
			{
				while (s[j] != ' ')
				{
					sn += s[j++];
				}
			}
			if (s[j] != ' ')
				v.push_back(s[j]);
		}
		n = stod(sn);
		for (auto j : v)
		{
			if (j == '@')
				n *= 3;
			else if (j == '%')
				n += 5;
			else
				n -= 7;
		}
		cout << n << '\n';
	}
	return 0;
}