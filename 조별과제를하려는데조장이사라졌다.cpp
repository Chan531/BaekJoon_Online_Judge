#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	if (!(n % 5))
		cout << n / 5;
	else
		cout << n / 5 + 1;
	return 0;
}