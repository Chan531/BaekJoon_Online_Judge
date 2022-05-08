#include <iostream>

using namespace std;

int main(void)
{
	int n, num, ans = 0;
	cin >> n;
	for (int i = 0; i < 5; i++)
	{
		cin >> num;
		if (n == num)
			ans++;
	}
	cout << ans;
}