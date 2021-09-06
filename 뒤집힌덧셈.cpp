#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	string x, y, z;
	int n, m = 0;
	cin >> x >> y;
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	n = stoi(x) + stoi(y);
	z = to_string(n);
	reverse(z.begin(), z.end());
	for (int i = 0; i < z.length(); i++)
	{
		if (z[i] == '0')
		{
			if (m != 0)
				cout << z[i];
		}
		else
		{
			cout << z[i];
			m++;
		}
	}
	return 0;
}