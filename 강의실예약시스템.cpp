#include <iostream>

using namespace std;

int n, m, arr[202020];

void input()
{
	cin >> n >> m;
}

void solution()
{
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (arr[a] <= b)
		{
			cout << "YES\n";
			arr[a] = c;
		}
		else
			cout << "NO\n";
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