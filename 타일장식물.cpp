#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<long long> v(81);
	v[1] = 1;
	v[2] = 1;
	for (int i = 3; i <= n; i++)
		v[i] = v[i - 2] + v[i - 1];
	cout << v[n] * 4 + v[n - 1] * 2;
	return 0;
}