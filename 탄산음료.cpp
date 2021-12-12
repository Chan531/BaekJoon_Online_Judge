#include <iostream>

using namespace std;

int main(void)
{
	int e, f, c, ans = 0, a;
	cin >> e >> f >> c;
	e += f;
	while (e >= c)
	{
		ans += e / c;
		a = e;
		e = e % c;
		e += a / c;
	}
	cout << ans;
	return 0;
}