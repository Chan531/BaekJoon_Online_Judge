#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	for (int i = 2; ; i++)
	{
		if (n % i)
		{
			cout << i << ' ' << n - 1;
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