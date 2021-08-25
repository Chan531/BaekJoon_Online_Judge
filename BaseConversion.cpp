#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int a, b, m, n, ab = 0, d;
	cin >> a >> b >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> n;
		ab += n * pow(a, m - i);
	}
	n = 0;

	while (pow(b, n) <= ab)
		n++;

	while (n != 0)
	{
		d = ab / pow(b, n - 1);
		cout << d << ' ';
		ab -= d * pow(b, n - 1);
		n--;
	}
	return 0;
}