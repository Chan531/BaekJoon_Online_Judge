#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int x;
	string y = "";
	cin >> x >> y;
	for (int i = 2; i >= 0; i--)
	{
		cout << x * (y[i] - '0') << '\n';
	}
	cout << x * stoi(y);
	return 0;
}