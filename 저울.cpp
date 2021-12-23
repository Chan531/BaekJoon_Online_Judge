#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
	int n, num, sum = 0;
	vector<int> arr, sumarr;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	if (arr[0] != 1)
	{
		cout << 1;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		sumarr.push_back(sum);
	}
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			cout << sumarr[i] + 1;
			break;
		}
		if (sumarr[i] + 1 < arr[i + 1])
		{
			cout << sumarr[i] + 1;
			break;
		}
	}
	return 0;
}