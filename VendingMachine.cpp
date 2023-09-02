#include <iostream>
#include <string>

using namespace std;

int ans = 5000;
string s;

void input()
{
	getline(cin, s);
}

void solution()
{
	for (int i = 0; i < s.length(); i += 2)
	{
		if (s[i] == '1')
			ans -= 500;

		else if (s[i] == '2')
			ans -= 800;

		else if (s[i] == '3')
			ans -= 1000;
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