#include <iostream>

using namespace std;

int main(void)
{
	int t, n, num, sum;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		sum = 0;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			sum += num;
		}
		cout << sum << '\n';
	}
	return 0;
}