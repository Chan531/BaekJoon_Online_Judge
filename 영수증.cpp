#include <iostream>

using namespace std;

int main(void)
{
	int n, num;
	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
			cin >> n;

		else
		{
			cin >> num;
			n -= num;
		}
	}
	cout << n;
	return 0;
}