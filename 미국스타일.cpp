#include <iostream>

using namespace std;

int main(void)
{
	double n, num;
	string point;
	cin >> n; 
	cout << fixed;
	cout.precision(4);
	while (n--)
	{
		cin >> num >> point;
		if (point == "kg")
			cout << num * 2.2046 << ' ' << "lb\n";
		else if (point == "lb")
			cout << num * 0.4536 << ' ' << "kg\n";
		else if (point == "l")
			cout << num * 0.2642 << ' ' << "g\n";
		else
			cout << num * 3.7854 << ' ' << "l\n";
	}
	return 0;
}