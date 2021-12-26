#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	cin >> str;
	if (str.length() >= 5 && str.substr(str.length() - 5, 5) == "driip")
		cout << "cute";
	else
		cout << "not cute";
	return 0;
}