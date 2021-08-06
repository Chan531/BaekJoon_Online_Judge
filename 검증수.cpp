#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int n, sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		sum += pow(n, 2);
	}
	cout << sum % 10;
	return 0;
}