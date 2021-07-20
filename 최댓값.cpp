#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int num;
	vector<pair<int, int>> v;
	for (int i = 0; i < 9; i++)
	{
		cin >> num;
		v.push_back(make_pair(num, i));
	}
	sort(v.begin(), v.end());
	cout << v[8].first << '\n' << v[8].second + 1;
	return 0;
}