#include <iostream>
#include <string>

using namespace std;

int n;
string s;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		cin >> s;

		if (s == "P=NP")
		{
			cout << "skipped\n";
			continue;
		}

		int idx = 0, ans = 0;

		string a = "";

		while (s[idx] != '+')
		{
			a += s[idx++];
		}

		ans += stoi(a);

		a = "";
		idx++;

		while (idx != s.length())
		{
			a += s[idx++];
		}

		cout << ans + stoi(a) << '\n';
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
	cout.tie(NULL);

	solve();
	return 0;
}