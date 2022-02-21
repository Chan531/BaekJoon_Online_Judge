#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

string binary, octal = "";
int idx, cnt;

void solve()
{
	cin >> binary;
	idx = binary.length() - 1;
	for (int i = idx; i >= 0; i -= 3)
	{
		cnt = 0;
		if (binary[i] == '1')
			cnt += 1;
		if (i > 0 && binary[i - 1] == '1')
			cnt += 2;
		if (i > 1 && binary[i - 2] == '1')
			cnt += 4;
		octal += to_string(cnt);
	}
	reverse(octal.begin(), octal.end());
	cout << octal;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}