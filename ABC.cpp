#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	string s;
	vector<int> v;
	map<char, int> m;
	for (int i = 0; i < 3; i++)
	{
		cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	m['A'] = v[0];
	m['B'] = v[1];
	m['C'] = v[2];
	cin >> s;
	for (auto i : s)
		cout << m[i] << ' ';
	return 0;
}