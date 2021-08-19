#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	int n = a % b;
	return gcd(b, n);
}

int main(void)
{
	int t, n, num;
	long long int sum;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		sum = 0;
		vector<int> v;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			v.push_back(num);
		}
		for (int j = 0; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				sum += gcd(v[j], v[k]);
			}
		}
		cout << sum << '\n';
	}
	return 0;
}