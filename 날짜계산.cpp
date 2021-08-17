#include <iostream>

using namespace std;

int main(void)
{
	int e, s, m;
	cin >> e >> s >> m;
	int i = 1;
	while (1)
	{
		if (e == 15)
			e = 0;
		if (s == 28)
			s = 0;
		if (m == 19)
			m = 0;
		if (i % 15 == e && i % 28 == s && i % 19 == m)
		{
			cout << i;
			break;
		}
		i++;
	}
	return 0;
}