#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	while (k != 0)
	{
		if (n >= 2 * m)
			n--;
		else
			m--;
		k--;
	}
	cout << min(n / 2, m);
	return 0;
}