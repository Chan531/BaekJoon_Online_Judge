#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	int a, p, b;
	vector<int> v, w(1000000);
	cin >> a >> p;
	v.push_back(a);
	w[a] = 1;
	for (int i = 0; ; i++)
	{
		b = 0;
		for (int div = 1000000; div > 0; div /= 10)
		{
			b += pow(v[i] / div, p);
			v[i] %= div;
		}

		if (!w[b])
		{
			v.push_back(b);
			w[b] = i + 2;
		}
		else
		{
			cout << w[b] - 1;
			break;
		}
	}
	return 0;
}