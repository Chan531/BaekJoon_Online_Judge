#include <iostream>

using namespace std;

int main(void)
{
	int n, k, fn = 1, fk = 1, fnk = 1;
	cin >> n >> k;
	for (int i = 2; i <= n; i++)
		fn *= i;
	for (int i = 2; i <= k; i++)
		fk *= i;
	for (int i = 2; i <= n - k; i++)
		fnk *= i;
	cout << fn / (fk * fnk);
	return 0;
}