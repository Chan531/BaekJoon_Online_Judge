#include <iostream>

using namespace std;

string s;

void input()
{
	cin >> s;
}

void solution()
{
	if (s == "Algorithm")
		cout << 204;

	else if (s == "DataAnalysis")
		cout << 207;

	else if (s == "ArtificialIntelligence")
		cout << 302;

	else if (s == "CyberSecurity")
		cout << "B101";

	else if (s == "Network")
		cout << 303;

	else if (s == "Startup")
		cout << 501;

	else
		cout << 105;

	cout << '\n';
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
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