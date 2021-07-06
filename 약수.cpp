#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;
	int num = 0;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cout << v[0] * v[v.size() - 1];
	return 0;
}