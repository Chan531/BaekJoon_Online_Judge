#include <iostream>

using namespace std;

int main(void)
{
	int l, a, b, c, d, ad, bd;
	cin >> l >> a >> b >> c >> d;
	ad = a / c;
	if (ad * c < a)
		ad++;
	bd = b / d;
	if (bd * d < b)
		bd++;
	ad > bd ? cout << l - ad : cout << l - bd;
	return 0;
}