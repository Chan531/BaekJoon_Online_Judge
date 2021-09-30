#include <iostream>

using namespace std;

int main(void)
{
	int k, n, s, t = 210;
	char c;
	cin >> k >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> c;
		t -= s;
		if (t <= 0)
			continue;
		if (c == 'T')
		{
			if (k == 8)
				k = 1;
			else
				k++;
		}
	}
	cout << k;
	return 0;
}