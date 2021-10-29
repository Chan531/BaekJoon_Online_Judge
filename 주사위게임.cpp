#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, a, b, c, ma = 0, p;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		if (a == b && b == c)
			p = 10000 + a * 1000;
		else if (a == b || a == c)
			p = 1000 + a * 100;
		else if (b == c)
			p = 1000 + b * 100;
		else
			p = max({ a,b,c }) * 100;
		if (p > ma)
			ma = p;
	}
	cout << ma;
	return 0;
}