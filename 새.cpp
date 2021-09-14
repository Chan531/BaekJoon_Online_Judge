#include <iostream>

using namespace std;

int main(void)
{
	int n, i = 1, count = 0;
	cin >> n;
	while (n > 0)
	{
		n -= i++;
		if (n < i)
			i = 1;
		count++;
	}
	cout << count;
	return 0;
}