#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(void)
{
	int n, al, nu;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		al = (s[0] - 'A') * 26 * 26 + (s[1] - 'A') * 26 + s[2] - 'A';
		nu = stoi(s.substr(4, 4));
		if (abs(al - nu) <= 100)
			cout << "nice\n";
		else
			cout << "not nice\n";
	}
	return 0;
}