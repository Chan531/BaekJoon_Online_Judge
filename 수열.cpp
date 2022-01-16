#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
	int n, k, num, ans = 0, sum, idx = 1;
	vector<int> arr(100001);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	ans = accumulate(arr.begin(), arr.begin() + k + 1, 0);
	sum = ans;
	for (int i = k + 1; i <= n; i++)
	{
		sum += arr[i] - arr[idx++];
		ans = max(sum, ans);
	}
	cout << ans;
	return 0;
}