#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
	double xa, xb, xc, ya, yb, yc;
	vector<double> v;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	if (xa == xb && xb == xc && xa == xc)
	{
		cout << -1;
		return 0;
	}
	if (ya == yb && yb == yc && ya == yc)
	{
		cout << -1;
		return 0;
	}
	if (xa == xb || xa == xc || xb == xc)
	{

	}
	else if (abs(ya - yb) / abs(xa - xb) == abs(ya - yc) / abs(xa - xc) && abs(ya - yc) / abs(xa - xc) == abs(yb - yc) / abs(xb - xc) && abs(ya - yb) / abs(xa - xb) == abs(yb - yc) / abs(xb - xc))
	{
		cout << -1;
		return 0;
	}
	v.push_back(sqrt(pow(xa - xb, 2) + pow(ya - yb, 2)));
	v.push_back(sqrt(pow(xb - xc, 2) + pow(yb - yc, 2)));
	v.push_back(sqrt(pow(xa - xc, 2) + pow(ya - yc, 2)));
	sort(v.begin(), v.end());
	cout << fixed;
	cout.precision(16);
	cout << 2 * (v[2] - v[0]);
	return 0;
}