#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int a = 0;
	int n = 0;
	vector<int> v;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	for (auto i : v)
		cout << i << ' ';
}