#include <iostream>

using namespace std;

int main(void)
{
	int t, money;
	cin >> t;
	while (t--)
	{
		cin >> money;
		cout << money / 25 << ' ';
		money %= 25;
		cout << money / 10 << ' ';
		money %= 10;
		cout << money / 5 << ' ';
		money %= 5;
		cout << money / 1 << '\n';
	}
	return 0;
}