#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	string s;
	while (1)
	{
		cin >> s;
		if (s == "0")
			break;
		string t = s;
		reverse(s.begin(), s.end());
		if (s == t)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}
	return 0;
}