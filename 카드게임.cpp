#include <iostream>

using namespace std;

int main(void)
{
	int n = 0, num;
	for (int i = 0; i < 5; i++)
	{
		cin >> num;
		n += num;
	}
	cout << n;
	return 0;
}