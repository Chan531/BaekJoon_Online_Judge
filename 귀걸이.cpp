#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
	int n, num;
	string name;
	char ringnum;
	for (int i = 1; ; i++)
	{
		cin >> n;
		cin.ignore();
		if (!n)
			break;
		map<int, pair<string, int>> ring;
		map<int, pair<string, int>>::iterator it;
		for (int j = 1; j <= n; j++)
		{
			getline(cin, name);
			ring[j].first = name;
			ring[j].second = 2;
		}
		for (int j = 0; j < 2 * n - 1; j++)
		{
			cin >> num >> ringnum;
			ring[num].second--;
		}
		for (it = ring.begin(); it != ring.end(); it++)
		{
			if (it->second.second)
				cout << i << ' ' << it->second.first << '\n';
		}
	}
	return 0;
}