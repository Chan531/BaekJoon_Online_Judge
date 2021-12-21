#include <iostream>
#include <cmath>

using namespace std;

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
	long long temp = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (temp > 0)
		return 1;
	else if (temp == 0)
		return 0;
	else
		return -1;
}

int main(void)
{
	pair<long long, long long> one, two, three, four;
	int l1, l2, l3, l4;
	cin >> one.first >> one.second >> two.first >> two.second >> three.first >> three.second >> four.first >> four.second;
	l1 = ccw(one.first, one.second, two.first, two.second, three.first, three.second);
	l2 = ccw(one.first, one.second, two.first, two.second, four.first, four.second);
	l3 = ccw(three.first, three.second, four.first, four.second, one.first, one.second);
	l4 = ccw(three.first, three.second, four.first, four.second, two.first, two.second);
	if (l1 * l2 == 0 && l3 * l4 == 0)
	{
		if (one > two)
			swap(one, two);

		if (three > four)
			swap(three, four);

		if (three <= two && one <= four)
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	if (l1 * l2 <= 0 && l3 * l4 <= 0)
		cout << 1;
	else
		cout << 0;
	return 0;
}