#include <iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a, b;
	cin >> a >> b;
	if (a == b)
	{
		cout << 0;
		return 0;
	}
	if (a > b)
	{
		long long c = b;
		b = a;
		a = c;
	}
	cout << b - a - 1 << '\n';
	for (long long i = a + 1; i < b; i++)
	{
		cout << i << ' ';
	}
	return 0;
}