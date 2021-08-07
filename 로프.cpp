#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i = 1; i <= n; i++)
	{
		v[i - 1] *= i;
	}
	cout << *max_element(v.begin(), v.end());
	return 0;
}