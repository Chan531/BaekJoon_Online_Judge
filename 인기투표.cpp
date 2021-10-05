#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
	int t, n, num, ma;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		vector<int> v(n + 1);
		ma = 0;
		for (int j = 1; j <= n; j++)
		{
			cin >> num;
			v[j] = num;
		}
		ma = *max_element(v.begin(), v.end());
		if (count(v.begin(), v.end(), ma) > 1)
		{
			cout << "no winner\n";
			continue;
		}
		if (accumulate(v.begin(), v.end(), 0) - ma < ma)
			cout << "majority winner " << max_element(v.begin(), v.end()) - v.begin() << '\n';
		else
			cout << "minority winner " << max_element(v.begin(), v.end()) - v.begin() << '\n';
	}
	return 0;
}