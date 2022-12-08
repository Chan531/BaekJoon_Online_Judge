#include <iostream>
#include <algorithm>

using namespace std;

int n, k, ans;
char str[20000];

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> str[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		// 만약 사람이라면 주변 범위에서 먹지 않은 햄버거 탐색
		if (str[i] == 'P')
		{
			// 주변 탐색
			for (int j = i - k; j <= i + k; j++)
			{
				if (j < 0)
					continue;

				if (j >= n)
					break;

				if (str[j] == 'H')
				{
					str[j] = 'E';
					ans++;
					break;
				}
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