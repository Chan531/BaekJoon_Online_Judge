#include <iostream>

using namespace std;

int n, k;
string ans = "See you next month";

void input()
{
	cin >> n;
}

void solution()
{
	while (n--)
	{
		int a, b;
		cin >> a >> b;

		if (a == 1) k += b;
		else
		{
			if (k < b)
			{
				ans = "Adios";
				break;
			}
			k -= b;
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

	solve();
	return 0;
}