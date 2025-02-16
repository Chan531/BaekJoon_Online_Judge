#include <iostream>
#include <unordered_map>

using namespace std;

int n, ans;
string s;
unordered_map<string, int> m;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		cin >> s;

		if (m[s]) continue;

		for (int i = 0; i < s.length(); i++)
		{
			string t = "";
			for (int j = 0; j < s.length(); j++)
				t += s[(i + j) % s.length()];
			m[t] = 1;
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