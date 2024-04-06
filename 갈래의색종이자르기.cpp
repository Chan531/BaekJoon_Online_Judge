#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 1; ; i++)
	{
		if (i * i * 2 == n)
		{
			cout << 8 * i;
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