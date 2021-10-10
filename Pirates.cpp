#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	string s;
	vector<int> v(26);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		v[s[i] - 'a']++;
	cout << char(max_element(v.begin(), v.end()) - v.begin() + 'a') << ' ' << *max_element(v.begin(), v.end());
	return 0;
}