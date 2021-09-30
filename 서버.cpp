#include <iostream>

using namespace std;

int main(void)
{
	int n, t, num, cnt = 0;
	cin >> n >> t;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		t -= num;
		if (t >= 0)
			cnt++;
	}
	cout << cnt;
	return 0;
}