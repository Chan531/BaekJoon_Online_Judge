#include <iostream>

using namespace std;

int main(void)
{
	int n, r, e, c;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> r >> e >> c;
		if (r > e - c)
			cout << "do not advertise\n";
		else if (r == e - c)
			cout << "does not matter\n";
		else
			cout << "advertise\n";
	}
	return 0;
}