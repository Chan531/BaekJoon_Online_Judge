#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < 5; i++)
		ans += pow(s[i] - '0', 5);
	cout << ans;
	return 0;
}