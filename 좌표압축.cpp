#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void)
{
	int n, num = 0;
	vector<int> v;
	map<int, int> m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	vector<int> w(v);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		m[v[i]] = i;
	}
	for (int i = 0; i < n; i++)
	{
		cout << m[w[i]] << ' ';
	}
	return 0;
}