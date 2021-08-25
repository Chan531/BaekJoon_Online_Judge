#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, div = 10007, sum;
	cin >> n;
	vector<int> v(n + 1);
	vector<int> num(10, 1);
	v[1] = 10;
	for (int i = 2; i <= n; i++)
	{
		sum = 1;
		for (int j = 1; j < 10; j++)
		{
			num[j] = num[j - 1] % div + num[j] % div;
			sum += num[j] % div;
		}
		v[i] = sum % div;
	}
	cout << v[n];
	return 0;
}