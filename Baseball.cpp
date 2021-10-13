#include <iostream>

using namespace std;

int main(void)
{
	int t, y, k, ys, ks;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		ys = 0;
		ks = 0;
		for (int j = 0; j < 9; j++)
		{
			cin >> y >> k;
			ys += y;
			ks += k;
		}
		if (ys > ks)
			cout << "Yonsei\n";
		else if (ys == ks)
			cout << "Draw\n";
		else
			cout << "Korea\n";
	}
	return 0;
}