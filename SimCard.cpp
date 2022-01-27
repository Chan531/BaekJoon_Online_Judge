#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m, a, b, c;
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		a = n * 30 + m * 40;
		b = n * 35 + m * 30;
		c = n * 40 + m * 20;
		cout << min({ a,b,c }) << '\n';
	}
	return 0;
}