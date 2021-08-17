#include <iostream>

using namespace std;

int main(void)
{
	int t, n, m;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		cout << m - n + 2 << '\n';
	}
	return 0;
}