#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	map<string, int> name;
	map<int, string> index;
	string s;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		index[i] = s;
		name[s] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (isalpha(s[0]))
			cout << name[s] << '\n';
		else
			cout << index[stoi(s)] << '\n';
	}
	return 0;
}