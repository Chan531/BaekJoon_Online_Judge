#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int sv(string s)
{
	int svalue = 0;
	for (int j = 0; j < s.length(); j++)
	{
		if (isdigit(s[j]))
			svalue += s[j] - '0';
	}
	return svalue;
}

int main(void)
{
	int n;
	vector<tuple<int, int, string>> v;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(make_tuple(s.length(), sv(s), s));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		cout << get<2>(v[i]) << '\n';
	return 0;
}