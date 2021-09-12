#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, k;
	vector<int> v;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		if (!(n % i))
			v.push_back(i);
	}
	sort(v.begin(), v.end());
	if (k > v.size())
		cout << 0;
	else
		cout << v[k - 1];
	return 0;
}