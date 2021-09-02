#include <iostream>

using namespace std;

int main(void)
{
	string s, str;
	cin >> s;
	for (auto i : s)
	{
		if ((i >= 65 && i <= 69) || i == 71 || i == 73 || i == 77 || i == 82)
		{

		}
		else
			str += i;
	}
	cout << str;
	return 0;
}