#include <iostream>

using namespace std;

long long n;
int m;

void input()
{
	cin >> n >> m;
}

void solution()
{
	if (n >= 6)
		cout << "Love is open door";

	else
	{
		for (int i = 2; i <= n; i++)
		{
			m++;
			m %= 2;
			cout << m << '\n';
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