#include <iostream>

using namespace std;

int main(void)
{
	int n, m, ans = 1;
	cin >> n >> m;
	if (n >= 3 && m >= 7)
		ans += m - 3;
	else
	{
		if (n >= 3)
			ans += m - 1;
		else if (n == 2)
		{
			if (m % 2)
				ans += m / 2;
			else
				ans += (m - 1) / 2;
		}
		if (ans > 4)
			ans = 4;
	}
	cout << ans;
	return 0;
}