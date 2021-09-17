#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num, sum = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		sum += num - 1;
	}
	cout << sum;
	return 0;
}