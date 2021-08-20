#include <iostream>

using namespace std;

int main(void)
{
	int z = 0, o = 0, n, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num == 1)
			o++;
		else
			z++;
	}
	o > z ? cout << "Junhee is cute!" : cout << "Junhee is not cute!";
	return 0;
}