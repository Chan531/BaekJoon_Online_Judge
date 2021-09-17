#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
	int n;
	vector<int> v(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		v[i] = n;
	}
	sort(v.begin(), v.end());
	cout << accumulate(v.begin(), v.end(), 0) / 5 << '\n' << v[2];
	return 0;
}