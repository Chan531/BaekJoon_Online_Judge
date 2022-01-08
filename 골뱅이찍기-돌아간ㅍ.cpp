#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i % 2)
			{
				for (int k = 0; k < 5 * n; k++)
					cout << '@';
				cout << '\n';
			}
			else
			{
				for (int k = 0; k < 5; k++)
				{
					for (int t = 0; t < n; t++)
					{
						if (k == 0 || k == 4)
							cout << '@';
						else
							cout << ' ';
					}
				}
				cout << '\n';
			}
		}
	}
	return 0;
}