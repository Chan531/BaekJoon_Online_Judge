#include <iostream>
#include <map>

using namespace std;

int n, m, k, a[55], b[55], c[55], ans;
map<int, int> check;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i];
	cin >> k;
	for (int i = 0; i < k; i++) cin >> c[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int l = 0; l < k; l++)
			{
				int val = a[i] + b[j] + c[l];
				if (check[val]) continue;
				check[val] = 1;

				while (val != 0)
				{
					if (val % 10 == 5 || val % 10 == 8) val /= 10;
					else break;
				}

				if (val == 0) ans++;
			}
		}
	}

	cout << ans << '\n';

	ans = 0;
	check.clear();
}

void solve()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		input();
		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}