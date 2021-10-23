#include <iostream>

using namespace std;

int main(void)
{
	int n, m = 1;
	cin >> n;
	while (1)
	{
		if (n - 1 == m + m * m)
		{
			cout << m;
			break;
		}
		m++;
	}
	return 0;
}