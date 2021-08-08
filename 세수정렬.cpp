#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int num;
	vector<int> v;
	for (int i = 0; i < 3; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (auto i : v)
		cout << i << ' ';
	return 0;
}