#include <iostream>

using namespace std;

int n, m, arr[1010];

void input()
{
	cin >> n >> m;
}

void solution()
{
	while (n--)
	{
		char c = '0';
		int cnt = 0;
		string s;
		cin >> s;

		for (int i = 0; i < m; i++)
		{
			if (s[i] == '0') continue;
			while (s[i] == '1')
				i++;
			cnt++;
		}

		arr[cnt]++;
	}

	for (int i = 500; i >= 0; i--)
	{
		if (arr[i])
		{
			cout << i << ' ' << arr[i];
			break;
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