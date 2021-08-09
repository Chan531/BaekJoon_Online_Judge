#include <iostream>

using namespace std;

int main(void)
{
	int n, m, max = 0, now = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> n >> m;
		now -= n - m;
		max < now ? max = now : 0;
	}
	cout << max;
	return 0;
}	