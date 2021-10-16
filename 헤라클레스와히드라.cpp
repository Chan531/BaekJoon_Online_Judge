#include <iostream>

using namespace std;

int main(void)
{
	int t, n;
	string s;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n >> s;
		for (auto j : s)
		{
			if (j == 'c')
				n++;
			else
				n--;
		}
		cout << "Data Set " << i << ":\n" << n << "\n\n";
	}
	return 0;
}