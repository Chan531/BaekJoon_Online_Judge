#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string h, n;
	cin >> h >> n;
	int ans = 0, hl = h.length(), nl = n.length();
	for (int i = 0; i < hl; i++)
	{
		if (h[i] == n[0])
		{
			if (h.substr(i, nl) == n)
				ans++;
		}
	}
	cout << ans;
	return 0;
}