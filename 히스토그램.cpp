#include <iostream>

using namespace std;

int main(void)
{
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		for (int j = 0; j < num; j++)
			cout << '=';
		cout << '\n';
	}
	return 0;
}