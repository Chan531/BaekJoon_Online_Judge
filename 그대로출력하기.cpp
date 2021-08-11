#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s = "";
	while (1)
	{
		getline(cin, s);
		if (s == "")
			break;
		cout << s << '\n';
	}
	return 0;
}