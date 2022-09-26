#include <iostream>

using namespace std;

int n, m, ans;

char jersey[1000001];
bool check[1000001];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> jersey[i];

		if (jersey[i] == 'S')
			jersey[i] = 'A';

		else if (jersey[i] == 'M')
			jersey[i] = 'B';

		else
			jersey[i] = 'C';
	}
}

void solution()
{
	char c;
	int i;

	while (m--)
	{
		cin >> c >> i;

		if (check[i])
			continue;

		if (c == 'S')
			c = 'A';

		else if (c == 'M')
			c = 'B';

		else
			c = 'C';

		if (jersey[i] >= c)
		{
			ans++;
			check[i] = 1;
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