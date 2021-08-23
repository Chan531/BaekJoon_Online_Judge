#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, k, l, e, h, point = 0, index = 0;
	vector<pair<int, int>> v;
	cin >> n >> l >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> e >> h;
		v.push_back(make_pair(h, e));
	}
	sort(v.begin(), v.end());
	while (k != 0)
	{
		if (index == n)
			break;
		if (l >= v[index].second)
		{
			point += 100;
			k--;
		}
		if (l >= v[index].first)
			point += 40;
		index++;
	}
	cout << point;
	return 0;
}