#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int n, btn = 0;
	string b;
	cin >> b >> n;
	for (int i = 1; i <= b.length(); i++)
	{
		if (isalpha(b[i - 1]))
			btn += pow(n, b.length() - i) * (b[i - 1] - 55);
		else
			btn += pow(n, b.length() - i) * (b[i - 1] - '0');
	}
	cout << btn;
	return 0;
}