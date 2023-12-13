#include <iostream>
#include <string>

using namespace std;

string a, b, c;
int ans;

void input()
{
	cin >> a >> b;
}

void solution()
{
	for (int i = 0; i < a.length(); i++)
	{
		if (isdigit(a[i]))
			continue;

		c += a[i];
	}

	for (int i = 0; i <= c.length() - b.length(); i++)
	{
		if (c.substr(i, b.length()) == b)
		{
			ans = 1;
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