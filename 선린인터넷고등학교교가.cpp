#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n;
	string str;
	cin >> n >> str;
	cout << str.substr(n - 5, 5);
	return 0;
}