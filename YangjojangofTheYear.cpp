#include <iostream>

using namespace std;

int main(void)
{
	int t, n, alcohol, maxalcohol = 0;
	string college, maxcollege;
	cin >> t;
	while (t--)
	{
		cin >> n;
		maxcollege = "";
		while (n--)
		{
			cin >> college >> alcohol;
			if (maxcollege == "" || maxalcohol < alcohol)
			{
				maxcollege = college;
				maxalcohol = alcohol;
			}
		}
		cout << maxcollege << '\n';
	}
	return 0;
}