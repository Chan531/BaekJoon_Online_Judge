#include <iostream>

using namespace std;

int main(void)
{
	string n;
	cin >> n;

	if (n[0] == '5' && n[1] == '5' && n[2] == '5')
		cout << "YES";
	else
		cout << "NO";

	return 0;
}