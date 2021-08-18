#include <iostream>

using namespace std;

int main(void)
{
	int n, zc = 0;
	cin >> n;
	for (int i = 5; i <= n; i += 5)
	{
		int num = i;
		while (num % 5 == 0)
		{
			zc++;
			num /= 5;
		}
	}
	cout << zc;
	return 0;
}