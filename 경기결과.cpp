#include <iostream>

using namespace std;

int main(void)
{
	int n, a = 0, b = 0, c, d;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c >> d;
		if (c > d)
			a++;
		else if (c < d)
			b++;
	}
	cout << a << ' ' << b;
	return 0;
}