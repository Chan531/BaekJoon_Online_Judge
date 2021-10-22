#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; ; i++)
	{
		if (n == 1)
		{
			cout << i;
			break;
		}
		if (n % 2)
			n = 3 * n + 1;
		else
			n /= 2;
		
	}
	return 0;
}