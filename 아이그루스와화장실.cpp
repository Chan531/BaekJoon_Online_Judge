#include <iostream>

using namespace std;

int n, m;
string s;

void input()
{
	cin >> n >> s >> m;
}

void solution()
{
	if (s == "annyong")
	{
		if (m % 2)
			cout << m;
		else
		{
			if (m + 1 > n)
				cout << m - 1;
			else
				cout << m + 1;
		}
	}

	else
	{
		if (m % 2)
		{
			if (m + 1 > n)
				cout << m - 1;
			else
				cout << m + 1;
		}
		else
			cout << m;
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