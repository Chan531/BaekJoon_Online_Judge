#include <iostream>
#include <string>

using namespace std;

void input()
{

}

void solution()
{
	while (!cin.eof())
	{
		string s;
		getline(cin, s);
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