#include <iostream>

using namespace std;

int n, m;
char map[50][50];
bool nc[50], mc[50];

void input()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'X')
			{
				nc[i] = 1;
				mc[j] = 1;
			}
		}
	}

	int ncnt = 0, mcnt = 0;

	for (int i = 0; i < n; i++)
		if (nc[i])
			ncnt++;

	for (int i = 0; i < m; i++)
		if (mc[i])
			mcnt++;

	n - ncnt > m - mcnt ? cout << n - ncnt : cout << m - mcnt;
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