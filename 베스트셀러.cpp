#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	string s;
	vector<pair<int, string>> v;
	map<string, int> m;
	map<string, int>::iterator it;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		m[s]++;
	}
	for (it = m.begin(); it != m.end(); it++)
	{
		v.push_back(make_pair(it->second, it->first));
	}
	sort(v.begin(), v.end());
	int point = v.size() - 1;
	while (point > 0 && v[point].first == v[point - 1].first)
		point--;
	cout << v[point].second;
	return 0;
}