#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int l, num, n, lidx, uidx, ans = 0;
	vector<int> arr;
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	cin >> n;
	lidx = lower_bound(arr.begin(), arr.end(), n) - arr.begin();
	uidx = upper_bound(arr.begin(), arr.end(), n) - arr.begin();
	if (lidx == 0 && uidx == 0)
	{
		lidx = 1;
		uidx = arr[0] - 1;
		while (lidx <= n)
		{
			if (lidx != n)
				ans += uidx - n + 1;
			else
				ans += uidx - n;
			lidx++;
		}
	}
	else if (lidx && arr[lidx] != n && uidx < l)
	{
		lidx = arr[lidx - 1] + 1; 
		uidx = arr[uidx] - 1;
		while (lidx <= n)
		{
			if (lidx != n)
				ans += uidx - n + 1;
			else
				ans += uidx - n;
			lidx++;
		}
	}
	cout << ans;
	return 0;
}