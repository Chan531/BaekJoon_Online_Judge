#include <iostream>
#include <map>
#include <tuple>

using namespace std;

map <tuple<int, int, int>, int> m;
map <tuple<int, int, int>, int>::iterator it;

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	it = m.find(make_tuple(a, b, c));
	if (it != m.end())
		return m[make_tuple(a, b, c)];
	if (a > 20 || b > 20 || c > 20)
		return m[make_tuple(20, 20, 20)] = w(20, 20, 20);
	if (a < b && b < c)
		return m[make_tuple(a, b, c)] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	return m[make_tuple(a, b, c)] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main(void)
{
	int a, b, c;
	while (1)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		else
			cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}
	return 0;
}