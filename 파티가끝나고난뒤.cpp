#include <iostream>

using namespace std;

int main(void)
{
	int l, p, n;
	cin >> l >> p;
	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		cout << (l * p - n) * -1 << ' ';
	}
	return 0;
}