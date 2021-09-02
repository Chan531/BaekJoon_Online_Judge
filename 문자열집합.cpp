#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, count = 0;
	string s;
	map<string, int> str;
	map<string, int>::iterator it;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		str[s] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		it = str.find(s);
		if (it != str.end())
			count++;
	}
	cout << count;
	return 0;
}