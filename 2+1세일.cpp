#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num, ans = 0;
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end(), greater<int>());
	for (int i = 1; i <= n; i++)
	{
		if (i % 3)
			ans += arr[i - 1];
	}
	cout << ans;
	return 0;
}