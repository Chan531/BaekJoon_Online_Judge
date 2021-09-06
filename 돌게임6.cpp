#include <iostream>

using namespace std;

int main(void)
{
	long long n;
	cin >> n;
	n %= 28;
	if (n == 1 || n == 3 || n == 4 || n == 5 || n == 6 || n == 8 || n == 10 || n == 11 || n == 12 || n == 13 || n == 15 || n == 17 || n == 18 || n == 19 || n == 20 || n == 22 || n == 24 || n == 25 || n == 26 || n == 27)
		cout << "SK";
	else
		cout << "CY";
	return 0;
}