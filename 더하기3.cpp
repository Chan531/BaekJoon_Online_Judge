#include <iostream>

using namespace std;

int main(void)
{
	int num, sum = 0;
	while (1)
	{
		cin >> num;
		if (cin.eof())
			break;
		sum += num;
	}
	cout << sum;
	return 0;
}