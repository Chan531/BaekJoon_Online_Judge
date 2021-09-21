#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int a, b, c, x, y, ans;
	cin >> a >> b >> c >> x >> y;
	if (a + b < 2 * c)
		cout << a * x + b * y;

	else
	{
		int mi = min(x, y);
		int ma = max(x, y);
		if (mi == x)
			ans =  mi * 2 * c + (ma - mi) * b;
		else
			ans = mi * 2 * c + (ma - mi) * a;
		ans > ma * 2 * c ? cout << ma * 2 * c : cout << ans;
	}
	return 0;
}