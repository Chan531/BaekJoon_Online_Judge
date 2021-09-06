#include <iostream>

using namespace std;

int main(void)
{
	string s;
	int n = 0;
	cin >> s;
	for (auto i : s)
		if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
			n++;
	cout << n;
	return 0;
}