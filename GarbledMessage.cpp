#include <iostream>
#include <string>

using namespace std;

string s;

void input()
{

}

void solution()
{
	while (getline(cin, s))
	{
		while (s.find("iiing") != string::npos)
			s.replace(s.find("iiing"), 5, "th");
		cout << s << '\n';
	}
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