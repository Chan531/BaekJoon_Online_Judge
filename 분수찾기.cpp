#include <iostream>

using namespace std;

int main(void)
{
	int n, a = 1, b = 1, cnt = 1;
	cin >> n;
	while (1)
	{
		for (int i = 1; ; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (cnt++ == n)
				{
					cout << a << '/' << b;
					return 0;
				}
				if (i % 2)
				{
					a--;
					b++;
				}
				else
				{
					a++;
					b--;
				}
			}
			if (i % 2)
				a++;
			else
				b++;
		}
	}
	return 0;
}