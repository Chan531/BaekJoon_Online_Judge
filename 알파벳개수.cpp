#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	string s = "";
	vector<int> v(26);
	cin >> s;
	for (auto i : s)
		v[i - 'a']++;
	for (auto i : v)
		cout << i << ' ';
	return 0;
}