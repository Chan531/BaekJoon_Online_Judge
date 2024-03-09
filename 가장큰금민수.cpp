#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

bool check(int n)
{
	while (n != 0)
	{
		int m = n % 10;

		if (m != 4 && m != 7)
			return 0;

		n /= 10;
	}

	return 1;
}

void solution()
{
	while (1)
	{
		if (check(n))
		{
			cout << n;
			break;
		}

		n--;
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