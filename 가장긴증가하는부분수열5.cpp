#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num;
	vector<int> arr, ans, ansindex(1000000), realans;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		if (ans.empty() || ans.back() < arr[i])
		{
			ans.push_back(arr[i]);
			ansindex[i] = ans.size();
		}
		else
		{
			int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
			ans[index] = arr[i];
			ansindex[i] = index + 1;
		}
	}
	cout << ans.size() << '\n';
	for (int i = n - 1; i >= 0; i--)
	{
		if (ansindex[i] == ans.size() - realans.size())
			realans.push_back(arr[i]);

		if (ans.size() == realans.size())
			break;
	}
	for (int i = realans.size() - 1; i >= 0; i--)
		cout << realans[i] << ' ';
	return 0;
}