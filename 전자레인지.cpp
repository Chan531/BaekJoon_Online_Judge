#include <iostream>

using namespace std;

int main(void)
{
	int t, fc = 0, oc = 0, tc = 0;
	cin >> t;
	if (t % 10 != 0)
	{
		cout << -1;
		return 0;
	}
	fc += t / 300;
	t %= 300;
	oc += t / 60;
	t %= 60;
	tc += t / 10;
	cout << fc << ' ' << oc << ' ' << tc;
	return 0;
}