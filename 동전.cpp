#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, coin[20], val[10001];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> coin[i];

	cin >> m;
}

void solution()
{
	val[0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (j < coin[i])
				continue;

			val[j] += val[j - coin[i]];
		}
	}

	cout << val[m] << '\n';
	memset(val, 0, sizeof(val));
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