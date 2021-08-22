#include <iostream>

using namespace std;

int main(void)
{
	int z, o, num;
	for (int i = 0; i < 3; i++)
	{
		z = 0; o = 0;
		for (int j = 0; j < 4; j++)
		{
			cin >> num;
			if (num == 0)
				z++;
			else
				o++;
		}
		if (z == 0)
			cout << "E\n";
		else if (z == 1)
			cout << "A\n";
		else if (z == 2)
			cout << "B\n";
		else if (z == 3)
			cout << "C\n";
		else
			cout << "D\n";
	}
	return 0;
}