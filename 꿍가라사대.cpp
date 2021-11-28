#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n;
	string s;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		getline(cin, s);
		if (s.length() > 10 && s.substr(0, 10) == "Simon says")
			cout << s.substr(10, s.length() - 10) << '\n';
	}
	return 0;
}