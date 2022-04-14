#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string cal;
	getline(cin, cal);
	cal[0] + cal[4] - '0' == cal[8] ? cout << "YES" : cout << "NO";
	return 0;
}