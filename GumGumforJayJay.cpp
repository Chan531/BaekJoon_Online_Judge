#include <iostream>
#include <string>

using namespace std;

int ans;
string s;

void input()
{
	while (!cin.eof())
	{
		string s;
		getline(cin, s);

		ans++;
	}

	cout << ans - 1;
}

void solution()
{

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