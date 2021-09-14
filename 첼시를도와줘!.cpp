#include <iostream>

using namespace std;

int main(void)
{
	int t, n, price, m;
	string s, name;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		m = 0;
		name = "";
		for (int j = 0; j < n; j++)
		{
			cin >> price >> s;
			if (price > m)
			{
				m = price;
				name = s;
			}
		}
		cout << name << '\n';
	}
	return 0;
}