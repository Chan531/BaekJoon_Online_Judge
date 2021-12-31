#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num;
	vector<int> arr;
	cin >> n;
	while (n--)
	{
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	for (auto i : arr)
		cout << i << ' ';
	return 0;
}