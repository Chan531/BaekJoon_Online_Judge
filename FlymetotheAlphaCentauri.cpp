#include <iostream>
#include <cmath>

using namespace std;

double tel(double x, double y)
{
	double d = y - x;
	double k = sqrt(d);
	double n = floor(k + 0.5);
	if (k > n)
		return n * 2;
	return n * 2 - 1;
}

int main(void)
{
	int n;
	double x, y;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		cout << tel(x, y) << '\n';
	}
	return 0;
}