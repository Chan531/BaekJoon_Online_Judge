#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num, maxh = 0, cnt = 0, ans = 0;
	cin >> n;
	while (n--)
	{
		cin >> num;
		if (num > maxh)
		{
			ans = max(ans, cnt);
			maxh = num;
			cnt = -1;
		}
		cnt++;
	}
	cout << max(cnt, ans);
	return 0;
}