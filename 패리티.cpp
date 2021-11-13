#include <iostream>

using namespace std;

int main(void)
{
	string s, t;
	while (1)
	{
		cin >> s;
		if (s == "#")
			break;
		t = "";
		int z = 0;
		int o = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '0')
			{
				z++;
				t += '0';
			}
			else if (s[i] == '1')
			{
				o++;
				t += '1';
			}
			else
			{
				if (s[i] == 'e')
				{
					if (o % 2)
						t += '1';
					else
						t += '0';
				}
				else
				{
					if (o % 2)
						t += '0';
					else
						t += '1';
				}
			}
		}
		cout << t << '\n';
	}
	return 0;
}