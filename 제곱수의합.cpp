#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void)
{
	int n, m;
	vector<int> v(100001, 100001);
	cin >> n;
	for (int i = 1; i <= sqrt(n); i++)
		v[i * i] = 1;
	for (int i = 2; i <= n; i++)
	{
		m = sqrt(i);
		for (int j = m; j > 0; j--)
			v[i] = min(v[i], v[i - j * j] + 1);
	}
	cout << v[n];
	return 0;
}