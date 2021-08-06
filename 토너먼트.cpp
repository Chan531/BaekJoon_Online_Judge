#include <iostream>

using namespace std;

int main(void)
{
	int n, k, l, count = 0;
	cin >> n >> k >> l;

	while (k != l)
	{
		if (k % 2 != 0)
			k++;
		if (l % 2 != 0)
			l++;
		k /= 2;
		l /= 2;
		count++;
	}

	cout << count;
	return 0;
}