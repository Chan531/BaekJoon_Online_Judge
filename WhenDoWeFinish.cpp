#include <iostream>
#include <string>

using namespace std;

string s, t;

void input()
{
	cin >> s >> t;
}

void solution()
{
	int sh = stoi(s.substr(0, 2));
	int th = stoi(t.substr(0, 2));
	int sm = stoi(s.substr(3, 2));
	int tm = stoi(t.substr(3, 2));
	string ansm, ansh;
	int p = 0;

	sm += tm;
	sh += th;

	if (sm >= 60)
		sh += sm / 60;

	sm %= 60;

	if (sm >= 10)
		ansm = to_string(sm);
	else
		ansm = "0" + to_string(sm);

	if (sh >= 24)
		p += sh / 24;

	sh %= 24;

	if (sh >= 10)
		ansh = to_string(sh);
	else
		ansh = "0" + to_string(sh);

	cout << ansh << ':' << ansm;
	if (p)
		cout << " +" << p;
	cout << '\n';
}

void solve()
{
	while (1)
	{
		input();
		if (s == "00:00" && t == "00:00") break;
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}