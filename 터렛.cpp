#include <iostream>
#include <cmath>

using namespace std;

int circle(int r1, int r2, int distance)
{
	int add = pow(r1 + r2, 2);
	int sub = pow(abs(r1 - r2), 2);
	if (distance > add)
		return 0;
	else if (distance == add)
		return 1;
	else
	{
		if (distance > sub)
			return 2;
		else if (distance == sub)
			return 1;
		else
			return 0;
	}
}

int main(void)
{
	int n, x1, y1, x2, y2, r1, r2, distance;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		distance = pow(x1 - x2, 2) + pow(y1 - y2, 2);
		if (x1 == x2 && y1 == y2)
		{
			if (r1 == r2)
				cout << -1;
			else
				cout << 0;
		}
		else
		{
			cout << circle(r1, r2, distance);
		}
		cout << '\n';
	}
	return 0;
}