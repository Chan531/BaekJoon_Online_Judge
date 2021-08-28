#include <iostream>

using namespace std;

int main(void)
{
	int n, a, b, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		sum += b % a;
	}
	cout << sum;
	return 0;
}