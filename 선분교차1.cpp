#include <iostream>
#include <cmath>

using namespace std;

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
	long long temp = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (temp > 0)
		return 1;
	else
		return -1;
}

int main(void)
{
	long long x1, x2, x3, x4, y1, y2, y3, y4;
	int l1, l2, l3, l4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	l1 = ccw(x1, y1, x2, y2, x3, y3);
	l2 = ccw(x1, y1, x2, y2, x4, y4);
	l3 = ccw(x3, y3, x4, y4, x1, y1);
	l4 = ccw(x3, y3, x4, y4, x2, y2);
	if (l1 * l2 < 0 && l3 * l4 < 0)
		cout << 1;
	else
		cout << 0;
	return 0;
}