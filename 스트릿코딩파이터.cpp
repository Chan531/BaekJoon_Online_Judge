#include <iostream>

using namespace std;

int main(void)
{
	int a, b, c, n, max = 0;
	cin >> a >> b >> c >> n;
	for (int i = 0; i < n; i++)
	{
		int o, n, p, oo = 0, nn = 0, pp = 0;
		for (int j = 0; j < 3; j++)
		{
			cin >> o >> n >> p;
			oo += o;
			nn += n;
			pp += p;
		}
		if (max < oo * a + nn * b + pp * c)
			max = oo * a + nn * b + pp * c;
	}
	cout << max;
	return 0;
}