#include <iostream>

using namespace std;

int main(void)
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << "Pairs for " << n << ": ";
		for (int i = 1; ; i++)
		{
			if (i >= n - i)
				break;
			if (i < n - i)
			{
				if (i > 1)
					cout << ", ";
				cout << i << ' ' << n - i;
			}
		}
		cout << '\n';
	}
	return 0;
}