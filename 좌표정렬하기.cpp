#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, x, y = 0;
	vector<pair<int, int>> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	return 0;
}