#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
	string line, s;
	map<string, int> str;
	cin >> line;
	int ans = 0, ll = line.length();
	for (int i = 0; i < ll; i++)
	{
		s = "";
		for (int j = i; j < ll; j++)
		{
			s += line[j];
			if (!str[s])
			{
				ans++;
				str[s] = 1;
			}
		}
	}
	cout << ans;
	return 0;
}