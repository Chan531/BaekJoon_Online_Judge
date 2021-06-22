#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b = 0;
		cin >> a >> b;
		cout << a + b << "\n";
	}
}