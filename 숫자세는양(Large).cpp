#include <iostream>
#include <cstring>

using namespace std;

int n, m, cnt, ans;
bool check[10];

void input()
{
	cin >> n;
}

void solution()
{
	ans = -1;
	cnt = 0;
	memset(check, 0, sizeof(check));

	if (!n)
		return;

	for (int i = 1; ; i++)
	{
		m = n * i;

		while (m != 0)
		{
			if (check[m % 10])
			{
				m /= 10;
				continue;
			}

			check[m % 10] = 1;
			cnt++;
			m /= 10;
		}

		if (cnt == 10)
		{
			ans = n * i;
			return;
		}
	}
}

void solve()
{
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++)
	{
		input();
		solution();
		ans == -1 ? cout << "Case #" << i << ": INSOMNIA\n" : cout << "Case #" << i << ": " << ans << '\n';
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}