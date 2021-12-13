#include <iostream>

using namespace std;

int main(void)
{
	int n, ans = 0, num, t = 30;
	cin >> n;
	while (n--)
	{
		cin >> num;
		if (t == 0)
			t = 30;
		if (num > t)
		{
			if (num - t <= num / 2)
				ans++;
			t = 0;
		}
		else
		{
			t -= num;
			ans++;
		}
	}
	cout << ans;
	return 0;
}