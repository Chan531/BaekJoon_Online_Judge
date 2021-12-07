#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	int n, num, start = 0, end, ans1, ans2, gap = 2000000001, currentgap;
	vector<int> arr;
	cin >> n;
	end = n - 1;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	while (start < end)
	{
		currentgap = abs(arr[start] + arr[end]);

		if (currentgap < gap)
		{
			gap = currentgap;
			ans1 = arr[start];
			ans2 = arr[end];
		}

		if (abs(arr[start]) > abs(arr[end]))
			start++;
		else
			end--;
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}