#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	int n, a = 0, mo = 0, mv;
	map<int, int> m;
	for (int i = 0; i < 10; i++)
	{
		cin >> n;
		m[n]++;
		a += n;
		if (m[n] > mo)
		{
			mo = m[n];
			mv = n;
		}
	}
	cout << a / 10 << '\n' << mv;
	return 0;
}