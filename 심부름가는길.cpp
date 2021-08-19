#include <iostream>

using namespace std;

int main(void)
{
	int num, x = 0, y = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> num;
		x += num / 60;
		y += num % 60;
	}
	x += y / 60;
	y %= 60;
	cout << x << '\n' << y;
	return 0;
}