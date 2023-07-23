#include <iostream>
#include <string>

using namespace std;

int ans = -1;
string s;

void input()
{

}

void solution()
{
	while (!cin.eof())
	{
		getline(cin, s);
		ans++;
	}

	cout << ans;
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