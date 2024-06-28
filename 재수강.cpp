#include <iostream>
#include <string>

using namespace std;

string s;
int n, ans;

void input()
{
	cin >> s >> n;
}

void solution()
{
	while (n--)
	{
		string str;
		cin >> str;

		if (s.substr(0, 5) == str.substr(0, 5))
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