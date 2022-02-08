#include <iostream>

using namespace std;

int main(void)
{
	int n;
	string num;
	cin >> n;
	while (n--)
	{
		cin >> num;
		if (num.back() % 2)
			cout << "odd\n";
		else
			cout << "even\n";
	}
	return 0;
}