#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	long long int x1, x2, y1, y2, r1, r2;
	unsigned long long rdist, dist;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	dist = pow(x1 - x2, 2) + pow(y1 - y2, 2);
	rdist = pow(r1 + r2, 2);
	if (rdist > dist)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}