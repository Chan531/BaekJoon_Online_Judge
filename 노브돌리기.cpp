#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, cangle, angle, ans = 0;
	cin >> n >> cangle;
	while (n--)
	{
		cin >> angle;
		ans += min({ abs(cangle - angle), 360 - cangle + angle, 360 + cangle - angle });
		cangle = angle;
	}
	cout << ans;
	return 0;
}