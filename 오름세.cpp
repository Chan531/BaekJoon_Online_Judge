#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num, idx;
	while (1)
	{
		cin >> n;
		if (cin.eof())
			break;
		vector<int> arr, ans;
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
			{
				idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
				ans[idx] = arr[i];
			}
		}
		cout << ans.size() << '\n';
	}
}