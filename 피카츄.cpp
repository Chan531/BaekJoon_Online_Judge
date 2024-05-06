#include <iostream>
#include <string>

using namespace std;

string s, ans = "YES";

void input()
{
	cin >> s;
}

void solution()
{
	int idx = 0;

	while (idx < s.length())
	{
		if (s.substr(idx, 2) == "pi" || s.substr(idx, 2) == "ka")
		{
			idx += 2;
			continue;
		}

		if (s.substr(idx, 3) == "chu")
		{
			idx += 3;
			continue;
		}

		ans = "NO";
		break;
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