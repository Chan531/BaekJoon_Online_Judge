#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	double a, b, v;
	cin >> a >> b >> v;
	int day = 0;
	v -= a;
	day += ceil(v / (a - b));
	day++;
	cout << day;
	return 0;
}