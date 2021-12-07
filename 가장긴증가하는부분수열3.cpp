#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num;
	vector<int> arr, ans;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		if (ans.empty() || ans.back() < arr[i])
			ans.push_back(arr[i]);

		else
			ans[lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin()] = arr[i];
	}
	cout << ans.size();
	return 0;
}