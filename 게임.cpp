#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	long long x, y, z, nx, ny, start = 1, end, mid, ans = 1000000001;
	cin >> x >> y;
	!y ? z = 0 : z = y * 100 / x;
	if (z >= 99)
	{
		cout << -1;
		return 0;
	}
	end = x;
	while (start <= end)
	{
		mid = (start + end) / 2;
		nx = x + mid;
		ny = y + mid;

		if (ny * 100 / nx > z)
		{
			ans = min(ans, mid);
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	cout << ans;
	return 0;
}