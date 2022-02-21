#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, idx, cnt, ans = 0;
string line;

void solve()
{
	cin >> n;
	while (n--)
	{
		cin >> line;
		idx = 0;
		cnt = 0;
		while (idx < line.length())
		{
			if (line[idx] == 'f')
			{
				if (line.substr(idx, 3) == "for")
				{
					cnt++;
					idx += 2;
				}
			}

			else if (line[idx] == 'w')
			{
				if (line.substr(idx, 5) == "while")
				{
					cnt++;
					idx += 4;
				}
			}

			idx++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}