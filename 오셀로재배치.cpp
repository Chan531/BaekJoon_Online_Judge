#include <iostream>
#include <algorithm>

using namespace std;

int n;
string s, t;

void input()
{
	cin >> n >> s >> t;
}

void solution()
{
	int b = 0, w = 0;

	for (int i = 0; i < n; i++)
	{
		if (s[i] != t[i])
		{
			if (t[i] == 'B')
				b++;

			else
				w++;
		}
	}

	cout << max(b, w) << '\n';
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}