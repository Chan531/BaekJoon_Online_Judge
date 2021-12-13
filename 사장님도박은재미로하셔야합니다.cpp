#include <iostream>

using namespace std;

int main(void)
{
	int n, ans = 0;
	while (1) {
		cin >> n;
		if (n == -1)
			break;
		ans += n;
	}
	cout << ans;
	return 0;
}