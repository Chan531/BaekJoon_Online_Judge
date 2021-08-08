#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	string s;
	vector<vector<char>> c;
	for (int i = 0; i < 5; i++)
	{
		cin >> s;
		vector<char> h;
		for (int j = 0; j < s.length(); j++)
			h.push_back(s[j]);
		for (int j = 0; j < 15 - s.length(); j++)
			h.push_back(' ');
		c.push_back(h);
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (c[j][i] != ' ')
				cout << c[j][i];
		}
	}
	return 0;
}