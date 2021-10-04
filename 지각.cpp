#include <iostream>

using namespace std;

int main(void)
{
	int n, m, j;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		j = 0;
		cin >> m;
		while (j + j * j <= m)
			j++;
		cout << j - 1 << '\n';
	}
	return 0;
}