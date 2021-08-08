#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	string s, t;
	cin >> s;
	t = s;
	reverse(s.begin(), s.end());
	if (s == t)
		cout << 1;
	else
		cout << 0;
	return 0;
}