#include <iostream>

using namespace std;

int main(void)
{
	int n, num, cnt;
	cin >> n;
	while (n--)
	{
		cnt = 0;
		cin >> num;
		for (int i = 1; i <= num; i++)
		{
			if (!(num % i))
				cnt++;
		}
		cout << num << ' ' << cnt << '\n';
	}
	return 0;
}