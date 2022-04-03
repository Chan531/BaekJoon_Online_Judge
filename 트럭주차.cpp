#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
	int a, b, c, s, e, t[101], ans = 0;
	memset(t, 0, sizeof(int) * 101);
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++)
	{
		cin >> s >> e;
		for (int j = s; j < e; j++)
			t[j]++;
	}
	for (int i = 1; i <= 100; i++)
	{
		if (t[i] == 1)
			ans += a;
		else if (t[i] == 2)
			ans += b * 2;
		else if (t[i] == 3)
			ans += c * 3;
	}
	cout << ans;
	return 0;
}