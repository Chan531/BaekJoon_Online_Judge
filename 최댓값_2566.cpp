#include <iostream>

using namespace std;

int main(void)
{
	int num, x, y, pnum = 0;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> num;
			if (pnum < num)
			{
				pnum = num;
				x = j;
				y = i;
			}
		}
	}
	cout << pnum << '\n' << y << ' ' << x;
	return 0;
}