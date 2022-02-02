#include <iostream>
#include <map>
#include <string>

using namespace std;

int n, idx;
string file;
map<string, int> extension;
map<string, int>::iterator it;

void input()
{
	cin >> n;
	while (n--)
	{
		idx = 0;
		cin >> file;
		while (file[idx] != '.')
			idx++;
		extension[file.substr(++idx, file.length() - idx)]++;
	}
}

void solution()
{
	for (it = extension.begin(); it != extension.end(); it++)
		cout << it->first << ' ' << it->second << '\n';
}

void solve()
{
	input();
	solution();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}