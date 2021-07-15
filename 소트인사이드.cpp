#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> v;
	string s = "";
	string answer = "";
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		v.push_back(s[i] - '0');
	}
	sort(v.begin(), v.end(), greater<>());
	for (int i = 0; i < v.size(); i++)
		answer += to_string(v[i]);
	cout << answer;
	return 0;
}