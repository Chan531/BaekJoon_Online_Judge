#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n;
	string sen;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		getline(cin, sen);
		if (sen.length() > 10 && sen.substr(0, 10) == "Simon says")
			cout << sen.substr(10, sen.length() - 10) << '\n';
	}
	return 0;
}