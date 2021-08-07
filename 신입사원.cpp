#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int t, n, num1, num2, count;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		vector<pair<int, int>> v, w;
		count = n;
		for (int j = 0; j < n; j++)
		{
			cin >> num1 >> num2;
			v.push_back(make_pair(num1, num2));
		}
		sort(v.begin(), v.end());
		int st1 = v[0].first;
		int st2 = v[0].second;
		for (int j = 1; j < n; j++)
		{
			if (st1 < v[j].first && st2 < v[j].second)
				count--;
			else
			{
				st1 = v[j].first;
				st2 = v[j].second;
			}
		}
		cout << count << '\n';
	}
	return 0;
}