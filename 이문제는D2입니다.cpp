#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s.substr(i, 2) == "d2" || s.substr(i, 2) == "D2")
		{
			cout << "D2";
			return 0;
		}
	}
	cout << "unrated";
	return 0;
}