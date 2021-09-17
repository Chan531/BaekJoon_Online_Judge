#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int n, count = 0, sq = 0;
	long long squ;
	cin >> n;
	for (int i = 1; ; i++)
	{
		squ = 9 * pow(10, sq++);
		if (n > squ)
		{
			n -= squ;
			count += i * squ;
		}
		else
		{
			count += i * n;
			n = 0;
		}
		if (!n)
			break;
	}
	cout << count;
	return 0;
}