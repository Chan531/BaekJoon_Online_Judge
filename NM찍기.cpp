#include <iostream>
#include <vector>

using namespace std;

int n, m;

void solve()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << i * m + j;
			if (j != m)
				cout << ' ';
		}
		cout << '\n';
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