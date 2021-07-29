#include <iostream>
#include <vector>

using namespace std;

vector<int> v(1000001);

int tile(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (v[n] != 0)
		return v[n];
	return v[n] = (tile(n - 1) + tile(n - 2)) % 15746;
}

int main(void)
{
	int n;
	cin >> n;
	cout << tile(n);
	return 0;
}