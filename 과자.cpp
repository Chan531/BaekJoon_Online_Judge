#include <iostream>

using namespace std;

int main(void)
{
	int k, n, m;
	cin >> k >> n >> m;
	int i = k * n - m;
	i >= 0 ? cout << i : cout << 0;
	return 0;
}