#include <iostream>

using namespace std;

int main()
{
	double base, make, sale = 0;
	cin >> base >> make >> sale;
	if (make >= sale)
		cout << -1;
	else
	{
		cout << int(base / (sale - make) + 1);
	}
	return 0;
}