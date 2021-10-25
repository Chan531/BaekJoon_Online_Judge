#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	string s, t;
	map<string, string> p;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> t;
		p[s] = t;
	}
	for (int j = 0; j < m; j++)
	{
		cin >> s;
		cout << p[s] << '\n';
	}
	return 0;
}