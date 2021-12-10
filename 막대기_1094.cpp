#include <iostream>

using namespace std;

int main(void)
{
	int n, ans = 0;
	cin >> n;
	while (n != 0)
	{
		if (n == 64)
			n -= 64;
		else if (n >= 32)
			n -= 32;
		else if (n >= 16)
			n -= 16;
		else if (n >= 8)
			n -= 8;
		else if (n >= 4)
			n -= 4;
		else if (n >= 2)
			n -= 2;
		else
			n -= 1;
		ans++;
	}
	cout << ans;
	return 0;
}