#include <iostream>

using namespace std;

int main(void)
{
	int n, a, b;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		cout << "Case " << i << ": " << a + b <<'\n';
	}
	return 0;
}