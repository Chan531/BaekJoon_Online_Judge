#include <iostream>

using namespace std;

int main(void)
{
	int n, num, y = 0, m = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		y += (num / 30 + 1) * 10;
		m += (num / 60 + 1) * 15;
	}
	if (y < m)
		cout << "Y " << y;
	else if (y > m)
		cout << "M " << m;
	else
		cout << "Y M " << y;
	return 0;
}