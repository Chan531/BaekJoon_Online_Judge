#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(void)
{
	int n, b, i = 0, m, d;
	string s = "";
	cin >> n >> b;
	while (n >= pow(b, ++i))
	{
	}
	while (i > 0)
	{
		d = pow(b, --i);
		m = n / d;
		if (m > 9)
			s += m + 55;
		else
			s += to_string(m);
		n -= m * d;
	}
	cout << s;
	return 0;
}