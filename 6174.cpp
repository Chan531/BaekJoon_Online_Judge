#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, cnt;

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int m;
		cin >> m;

		cnt = 0;

		while (1)
		{
			if (m == 6174)
			{
				cout << cnt << '\n';
				break;
			}

			string s = to_string(m);
			sort(s.begin(), s.end());
			while (s.length() != 4)
				s = "0" + s;
			string t = "";
			for (int i = s.length() - 1; i >= 0; i--) t += s[i];

			m = stoi(t) - stoi(s);
			cnt++;
		}
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

	solve();
	return 0;
}