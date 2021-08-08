#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	string s;
	vector<string> str;
	cin >> s;
	for (int i = s.length(); i > 0; i--)
	{
		str.push_back(s.substr(s.length() - i, i));
	}
	sort(str.begin(), str.end());
	for (auto i : str)
		cout << i << '\n';
	return 0;
}