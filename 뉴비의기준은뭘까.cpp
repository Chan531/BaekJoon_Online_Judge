#include <iostream>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	if (m == 1 || m == 2)
		cout << "NEWBIE!";
	else if (m <= n)
		cout << "OLDBIE!";
	else
		cout << "TLE!";
	return 0;
}