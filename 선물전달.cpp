#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	long long k = 1000000000;
	cin >> n;
	vector<long long> v(n + 1);
	v[1] = 0;
	v[2] = 1;
	for (int i = 3; i <= n; i++)
		v[i] = ((i - 1) * (v[i - 1] + v[i - 2]) % k) % k;
	cout << v[n];
	return 0;
}