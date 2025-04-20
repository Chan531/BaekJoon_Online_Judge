#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n, m;
string str, s, t;
map<char, int> c;
vector<int> v;

void input()
{
	cin >> n >> m;
	cin.ignore();
	getline(cin, str);
}

void init()
{
	c['A'] = 3;
	c['B'] = 2;
	c['C'] = 1;
	c['D'] = 2;
	c['E'] = 4;
	c['F'] = 3;
	c['G'] = 1;
	c['H'] = 3;
	c['I'] = 1;
	c['J'] = 1;
	c['K'] = 3;
	c['L'] = 1;
	c['M'] = 3;
	c['N'] = 2;
	c['O'] = 1;
	c['P'] = 2;
	c['Q'] = 2;
	c['R'] = 2;
	c['S'] = 1;
	c['T'] = 2;
	c['U'] = 1;
	c['V'] = 1;
	c['W'] = 1;
	c['X'] = 2;
	c['Y'] = 2;
	c['Z'] = 1;
}

void solution()
{
	init();

	for (int i = 0; i < n; i++)
		s += str[i];
	
	for (int i = 1; i <= m; i++)
		t += str[n + i];

	for (int i = 0; i < max(n, m); i++)
	{
		if (i < n) v.push_back(c[s[i]]);
		if (i < m) v.push_back(c[t[i]]);
	}

	while (v.size() > 2)
	{
		vector<int> temp;
		for (int i = 1; i < v.size(); i++)
			temp.push_back((v[i] + v[i - 1]) % 10);
		v = temp;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (!i && !v[i]) continue;
		cout << v[i];
	}

	cout << "%";
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