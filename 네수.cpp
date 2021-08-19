#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	a += b;
	c += d;
	long long s1 = stoll(a);
	long long s2 = stoll(c);
	cout << s1 + s2;
	return 0;
}