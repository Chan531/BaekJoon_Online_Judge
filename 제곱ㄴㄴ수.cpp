#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	long long min, max, n, mul;
	int answer = 0;
	cin >> min >> max;
	vector<int> v(1000001);
	for (long long i = 2; i <= sqrt(max); i++)
	{
		mul = pow(i, 2);
		n = min / mul;
		if (min % mul)
			n++;
		for (long long j = n; j * mul <= max; j++)
			v[j * mul - min + 1] = 1;               
	}
	for (long long i = 1; i <= max - min + 1; i++)
		if (!v[i])
			answer++;
	cout << answer;
	return 0;
}