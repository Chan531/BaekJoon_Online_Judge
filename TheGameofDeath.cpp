#include <iostream>
#include <cstring>
#define N 10010

using namespace std;

int n, point[N];
bool check[N];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> point[i];
}

void solution()
{
	check[1] = 1;
	int cur = 1;
	int cnt = 0;

	while (1)
	{
		int next = point[cur];
		cnt++;

		if (next == n)
		{
			cout << cnt << '\n';
			break;
		}

		if (check[next])
		{
			cout << 0 << '\n';
			break;
		}
		
		check[next] = 1;
		cur = next;
	}

	memset(check, 0, sizeof(check));
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