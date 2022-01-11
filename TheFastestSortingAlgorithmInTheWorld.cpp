#include <iostream>

using namespace std;

int main(void)
{
	int n, num;
	for (int i = 1; ; i++)
	{
		cin >> n;
		if (n == 0)
			break;
		while (n--)
			cin >> num;
		cout << "Case " << i << ": Sorting... done!\n";
	}
	return 0;
}