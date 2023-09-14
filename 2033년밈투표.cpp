#include <iostream>
#include <string>

using namespace std;

int n;
string s, ans = "No";

void input()
{
	cin >> n;
}

bool check()
{
	if (s == "Never gonna give you up")
		return true;

	if (s == "Never gonna let you down")
		return true;

	if (s == "Never gonna run around and desert you")
		return true;

	if (s == "Never gonna make you cry")
		return true;

	if (s == "Never gonna say goodbye")
		return true;

	if (s == "Never gonna tell a lie and hurt you")
		return true;

	if (s == "Never gonna stop")
		return true;

	return false;
}

void solution()
{
	cin.ignore();

	while (n--)
	{
		getline(cin, s);

		if (!check())
			ans = "Yes";
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