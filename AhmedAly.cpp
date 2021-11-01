#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int n, a, b, c;
	char d, e;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> d >> b >> e >> c;
		if (d == '+')
		{
			if (a + b == c)
				cout << "Case " << i << ": YES\n";
			else
				cout << "Case " << i << ": NO\n";
		}
		else
		{
			if (a - b == c)
				cout << "Case " << i << ": YES\n";
			else
				cout << "Case " << i << ": NO\n";
		}
	}
	return 0;
}