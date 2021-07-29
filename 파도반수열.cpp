#include <iostream>
#include <vector>

using namespace std;

vector<long long> v(101);

long long pado(int n)
{
	if (n == 1 || n == 2 || n == 3)
		return 1;
	if (n == 4 || n == 5)
		return 2;
	if (v[n] != 0)
		return v[n];
	return v[n] = pado(n - 1) + pado(n - 5);
}

int main(void)
{
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		cout << pado(num) << '\n';
	}
	return 0;
}