#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	vector<int> v;
	for (int i = 0; i < 3; i++)
	{
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	cout << v[1];
	return 0;
}