#include <iostream>

using namespace std;

int main(void)
{
	int n, num, vio = 0;
	cin >> n;
	for (int i = 0; i < 5; i++)
	{
		cin >> num;
		if (n == num)
			vio++;
	}
	cout << vio;
	return 0;
}