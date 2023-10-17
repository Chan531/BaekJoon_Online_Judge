#include <iostream>
#include <unordered_map>

using namespace std;

int n;
unordered_map<string, int> p;
unordered_map<string, int>::iterator it;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		p[s]++;
	}
}

void solution()
{
	for (int i = 1; i < n; i++)
	{
		string s;
		cin >> s;
		p[s]--;
	}

	for (it = p.begin(); it != p.end(); it++)
		if (it->second)
			cout << it->first;
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

	solve();
	return 0;
}