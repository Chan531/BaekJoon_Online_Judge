#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	int t, n, mul;
	string name, type;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		map<string, int> m;
		map<string, int>::iterator it;
		mul = 1;
		for (int j = 0; j < n; j++)
		{
			cin >> name >> type;
			m[type]++;
		}
		for (it = m.begin(); it != m.end(); it++)
			mul *= it->second + 1;
		cout << mul - 1 << '\n';
	}
	return 0;
}