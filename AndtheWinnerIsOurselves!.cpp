#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> arr;
	int t, cnt, sumt = 0, ans = 0;
	for (int i = 0; i <= 10; i++)
	{
		cin >> t >> cnt;
		arr.push_back(t);
		if (cnt != 0)
			ans += cnt * 20;
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i <= 10; i++)
	{
		sumt += arr[i];
		ans += sumt;
	}
	cout << ans;
	return 0;
}