#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n;
	string s;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		s[0] = toupper(s[0]);
		cout << s << '\n';
	}
	return 0;
}