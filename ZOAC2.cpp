#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
	int ans = 0, arrow = 'A';
	string line;
	cin >> line;
	for (int i = 0; i < line.length(); i++)
	{
		ans += min(abs(arrow - line[i]), 26 - abs(arrow - line[i]));
		arrow = line[i];
	}
	cout << ans;
	return 0;
}