#include <iostream>

using namespace std;

string s;
int ans;

void input()
{
	cin >> s;
}

void solution()
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'N')
			continue;

		for (int j = i; j < s.length(); j += (i + 1))
		{
			if (s[j] == 'N') s[j] = 'Y';
			else s[j] = 'N';
		}

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