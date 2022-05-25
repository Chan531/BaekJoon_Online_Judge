#include <iostream>

using namespace std;

int main(void)
{
	int a, b;
	long long sum = 1;

	cin >> a >> b;

	while (a <= b)
	{
		sum *= a * (a + 1) / 2;

		if (sum > 14579)
			sum %= 14579;
		a++;
	}

	cout << sum;

	return 0;
}