#include <iostream>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n;
    m = n % 8;
	if (m == 1)
		cout << 1;
	else if (m == 0 || m == 2)
		cout << 2;
	else if (m == 3 || m == 7)
		cout << 3;
	else if (m == 4 || m == 6)
		cout << 4;
	else
		cout << 5;
	return 0;
}