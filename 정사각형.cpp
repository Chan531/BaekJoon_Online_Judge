#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
	long long int t, num1, num2;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		vector<pair<long long int, long long int>> v;
		vector<long long int> l;
		for (int j = 0; j < 4; j++)
		{
			cin >> num1 >> num2;
			v.push_back(make_pair(num1, num2));
		}
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (k != j)
				{
					l.push_back(pow(v[j].first - v[k].first, 2) + pow(v[j].second - v[k].second, 2));
				}
			}
		}
		if (count(l.begin(), l.end(), *min_element(l.begin(), l.end())) == 8)
		{
			sort(l.begin(), l.end());
			if (l[0] * 2 == l[8])
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else
			cout << 0 << '\n';
	}
	return 0;
}