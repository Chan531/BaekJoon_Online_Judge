	#include <iostream>
	#include <algorithm>

	using namespace std;

	int main(void)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << min(a + d, b + c);
		return 0;

	}