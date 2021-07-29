#include <iostream>
#include <cctype>

using namespace std;

int main(void)
{
	string s = "";
	string t = "";
	cin >> s;
	for (auto i : s)
	{
		if (isupper(i))
			t += i;
	}
	cout << t;
	return 0;
}