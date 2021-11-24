#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	int k, n, num, lgap;
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> n;
		vector<int> arr;
		lgap = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			arr.push_back(num);
		}
		sort(arr.begin(), arr.end());
		for (int j = 0; j < n - 1; j++)
		{
			if (abs(arr[j] - arr[j + 1]) > lgap)
				lgap = abs(arr[j] - arr[j + 1]);
		}
		cout << "Class " << i << '\n' << "Max " << arr[n - 1] << ", Min " << arr[0] << ", Largest gap " << lgap << '\n';
	}
	return 0;
}