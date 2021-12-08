#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	int n, start, end;
	long long num, gap = 3000000001, ans1, ans2, ans3;
	vector<long long> arr;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
	{
		start = 0;
		end = n - 1;
		while (start < end)
		{
			if (start == i)
			{
				start++;
				continue;
			}

			if (end == i)
			{
				end--;
				continue;
			}

			if (abs(arr[i] + arr[start] + arr[end]) < gap)
			{
				gap = abs(arr[i] + arr[start] + arr[end]);
				if (i < start)
				{
					ans1 = arr[i];
					ans2 = arr[start];
					ans3 = arr[end];
				}
				else if (i > start && i < end)
				{
					ans1 = arr[start];
					ans2 = arr[i];
					ans3 = arr[end];
				}
				else
				{
					ans1 = arr[start];
					ans2 = arr[end];
					ans3 = arr[i];
				}
			}

			if (arr[end] + arr[start] > abs(arr[i]))
				end--;

			else
				start++;
		}
	}
	cout << ans1 << ' ' << ans2 << ' ' << ans3;
	return 0;
}