#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	long long sum;
	cin >> n;
	vector<int> v(n + 1);
	vector<int> s(10000);
	v[1] = 9;
	for (int i = 1; i <= 9; i++)
		s[i] = 1;
	for (int i = 2; i <= n; i++)
	{
		sum = 0;
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
				s[10 * (i - 1)] = s[10 * (i - 2) + 1] % 1000000000;
			else if (j == 9)
				s[10 * (i - 1) + j] = s[10 * (i - 2) + 8] % 1000000000;
			else
				s[10 * (i - 1) + j] = s[10 * (i - 2) + j - 1] % 1000000000 + s[10 * (i - 2) + j + 1] % 1000000000;
			sum += s[10 * (i - 1) + j] % 1000000000;
		}
		v[i] = sum % 1000000000;
	}
	cout << v[n];
	return 0;
}