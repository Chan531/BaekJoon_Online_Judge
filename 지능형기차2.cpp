#include <iostream>

using namespace std;

int main(void)
{
	int n, m, p = 0, pp = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> n >> m;
		p += m - n;
		if (pp < p)
			pp = p;
	}
	cout << pp;
	return 0;
}