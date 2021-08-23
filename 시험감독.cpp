#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, num, b, c;
	long long p = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	cin >> b >> c;
	for (int i = 0; i < n; i++)
		v[i] -= b;
	p += n;
	for (int i = 0; i < n; i++)
	{
		if (v[i] > 0)
		{
			if (v[i] % c == 0)
				p += v[i] / c;
			else
				p += v[i] / c + 1;
		}
	}
	cout << p;
	return 0;
}