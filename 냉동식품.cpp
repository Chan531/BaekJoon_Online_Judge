#include <iostream>

using namespace std;

int main(void)
{
	int h1, h2, m1, m2, n, cnt = 0;
	cin >> h1 >> m1 >> h2 >> m2 >> n;
	while (1)
	{
		if (h1 / 10 == n || h1 % 10 == n || m1 / 10 == n || m1 % 10 == n)
			cnt++;
		if (h1 == h2 && m1 == m2)
			break;
		m1++;
		if (m1 == 60)
		{
			m1 = 0;
			h1++;
		}
	}
	cout << cnt;
	return 0;
}