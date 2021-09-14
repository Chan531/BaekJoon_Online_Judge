#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		vector<int> v;
		for (int j = 0; j < 7; j++)
		{
			cin >> n;
			if (!(n % 2))
				v.push_back(n);
		}
		sort(v.begin(), v.end());
		cout << accumulate(v.begin(), v.end(), 0) << ' ' << v[0] << '\n';
	}
	return 0;
}