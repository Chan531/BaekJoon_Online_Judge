#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int n;
	double price;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> price;
		price = price * 4 / 5;
		price *= 100;
		round(price);
		price /= 100;
		cout << fixed;
		cout.precision(2);
		cout << '$' << price << '\n';
	}
	return 0;
}