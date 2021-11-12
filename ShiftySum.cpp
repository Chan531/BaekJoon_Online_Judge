#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int n, k, s = 0;
	cin >> n >> k;
	for (int i = 0; i <= k; i++)
		s += pow(10, i) * n;
	cout << s;
	return 0;
}