#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int l[3];
	for (int i = 0; i < 3; i++)
		cin >> l[i];
	sort(l, l + 3);
	if (l[0] + l[1] > l[2])
		cout << l[0] + l[1] + l[2];
	else
		cout << (l[0] + l[1]) * 2 - 1;
	return 0;
}