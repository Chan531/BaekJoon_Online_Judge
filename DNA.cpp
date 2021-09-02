#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, m, num = 0;
	string s, str = "";
	vector<string> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);
	}
	for (int i = 0; i < m; i++)
	{
		vector<int> a(26);
		for (int j = 0; j < n; j++)
		{
			char c = v[j].at(i);
			a[c - 'A']++;
		}
		str += max_element(a.begin(), a.end()) - a.begin() + 'A';
		num += n - *max_element(a.begin(), a.end());
	}
	cout << str << '\n' << num;
	return 0;
}