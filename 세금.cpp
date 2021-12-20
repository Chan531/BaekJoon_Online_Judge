#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	cout << n * 78 / 100 << ' ' << n * 80 / 100 + n * 20 / 100 * 78 / 100;
	return 0;
}