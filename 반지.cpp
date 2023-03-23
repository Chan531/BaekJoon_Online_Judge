#include <iostream>
#include <string>

using namespace std;

string s, t;
int n, ans;

void input()
{
	cin >> s >> n;
}

void solution()
{
	int sl = s.length();

	while (n--)
	{
		cin >> t;
		int tl = t.length();

		t += t;

		for (int i = 0; i < tl; i++)
		{
			if (t.substr(i, sl) == s)
			{
				ans++;
				break;
			}
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
	cout.tie(NULL);

	solve();
	return 0;
}