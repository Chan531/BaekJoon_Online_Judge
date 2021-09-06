#include <iostream>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	for (auto i : s)
	{
		if (i == 'A' || i == 'B' || i == 'C')
			cout << char(i + 23);
		else
			cout << char(i - 3);
	}
	return 0;
}