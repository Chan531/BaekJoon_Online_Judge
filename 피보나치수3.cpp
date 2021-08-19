#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	unsigned long long n;
	vector<int> v(1500001);
	v[1] = 1;
	v[2] = 1;
	cin >> n;
	n %= 1500000;
	for (int i = 3; i <= n; i++)
	{
		v[i] = v[i - 1] + v[i - 2];
		v[i] %= 1000000;
	}
	cout << v[n];
	return 0;
}