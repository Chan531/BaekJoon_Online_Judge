#include <iostream>

using namespace std;

int main(void)
{
	int r, c, rg, rp, cg, cp, count = 0;
	cin >> r >> c >> rg >> cg >> rp >> cp;
	string s;
	for (int i = 0; i < r; i++)
	{
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			if (s[j] == 'P')
				count++;
		}
	}
	rp * cp == count ? cout << 0 : cout << 1;
	return 0;
}