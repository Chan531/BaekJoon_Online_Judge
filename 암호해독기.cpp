#include <iostream>
#include <string>

using namespace std;

int n, arr[53];
string s, ans = "y";

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		arr[m]++;
	}

	cin.ignore();
	getline(cin, s);
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			arr[0]--;
			continue;
		}

		if (isupper(s[i]))
			arr[s[i] - 'A' + 1]--;

		else
			arr[s[i] - 'a' + 27]--;
	}

	for (int i = 0; i < 53; i++)
	{
		if (arr[i] != 0)
		{
			ans = "n";
			break;
		}
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