#include <iostream>

using namespace std;

string s;
int a, b;

void input()
{
	cin >> s;
}

void solution()
{
	for (auto i : s)
	{
		if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
		{
			a++;
			b++;
		}

		if (i == 'y')
			b++;
	}

	cout << a << ' ' << b;
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