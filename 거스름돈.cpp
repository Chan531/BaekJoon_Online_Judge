#include <iostream>

using namespace std;

int main(void)
{
	int n, count = 0;
	cin >> n;
	int change = 1000 - n;
	while (1000 - n >= 500)
	{
		n += 500;
		count++;
	}
	while (1000 - n >= 100)
	{
		n += 100;
		count++;
	}
	while (1000 - n >= 50)
	{
		n += 50;
		count++;
	}
	while (1000 - n >= 10)
	{
		n += 10;
		count++;
	}
	while (1000 - n >= 5)
	{
		n += 5;
		count++;
	}
	while (1000 - n >= 1)
	{
		n += 1;
		count++;
	}
	cout << count;
	return 0;
}