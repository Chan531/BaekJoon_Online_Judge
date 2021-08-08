#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int r = 0;
	string s;
	cin >> s;
	sort(s.begin(), s.end(), greater<int>());
	if (s[s.size() - 1] != '0')
	{
		cout << -1;
		return 0;
	}
	for (auto i : s)
	{
		r += (i - '0') % 3;
	}
	if (r % 3 == 0)
		cout << s;
	else
		cout << -1;
	return 0;
}