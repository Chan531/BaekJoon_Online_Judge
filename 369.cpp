#include <iostream>
#include <string>

using namespace std;

int n, ans;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		string s = to_string(i);

		for (int j = 0; j < s.length(); j++)
			if (s[j] == '3' || s[j] == '6' || s[j] == '9')
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
	cout.tie(NULL);

	solve();
	return 0;
}