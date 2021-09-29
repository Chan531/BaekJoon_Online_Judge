#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	double total = 0;
	string s;
	map<string, double> m;
	map<string, double> per;
	map<string, double>::iterator it;
	cout << fixed;
	cout.precision(4);
	while (1)
	{
		getline(cin, s);
		if (cin.eof())
		{
			break;
		}
		m[s]++;
		total++;
	}
	for (it = m.begin(); it != m.end(); it++)
	{
		per[it->first] = it->second / total;
		cout << it->first << ' ' << it->second / total * 100 << '\n';
	}
	return 0;
}