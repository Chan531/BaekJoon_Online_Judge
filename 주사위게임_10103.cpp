#include <iostream>

using namespace std;

int main(void)
{
	int n, a = 100, b = 100, an, bn;
	cin >> n;
	while (n--)
	{
		cin >> an >> bn;
		
		if (an > bn)
			b -= an;

		else if (an < bn)
			a -= bn;
	}
	cout << a << '\n' << b;
	return 0;
}