#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	string s, t;
	cin >> s >> t;
	while (t.length() != s.length())
	{
		if (t.back() == 'B')
		{
			t.pop_back();
			reverse(t.begin(), t.end());
		}
		else
			t.pop_back();
	}
	s == t ? cout << 1 : cout << 0;
	return 0;
}