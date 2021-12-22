#include <iostream>

using namespace std;

int main(void)
{
	int t, car, option, optnum, optvalue;
	cin >> t;
	while (t--)
	{
		cin >> car >> option;
		while (option--)
		{
			cin >> optnum >> optvalue;
			car += optnum * optvalue;
		}
		cout << car << '\n';
	}
	return 0;
}