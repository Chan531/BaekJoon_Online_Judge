#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	vector<int> a(46), b(46);
	a[1] = 0;
	b[1] = 1;
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		a[i] = b[i - 1];
		b[i] = a[i - 1] + b[i - 1];
	}
	cout << a[n] << ' ' << b[n];
	return 0;
}