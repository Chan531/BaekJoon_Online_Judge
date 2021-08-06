#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	int x, y;
	map<int, int> xx;
	map<int, int> yy;
	map<int, int>::iterator it;

	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		xx[x]++;
		yy[y]++;
	}
	for (it = xx.begin(); it != xx.end(); it++)
	{
		if (it->second != 2)
			cout << it->first << ' ';
	}
	for (it = yy.begin(); it != yy.end(); it++)
	{
		if (it->second != 2)
			cout << it->first;
	}
	return 0;
}