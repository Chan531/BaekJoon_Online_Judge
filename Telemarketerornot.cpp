#include <iostream>

using namespace std;

char c[4];

void input()
{
	for (int i = 0; i < 4; i++)
		cin >> c[i];
}

void solution()
{
	if (c[0] != '8')
	{
		if (c[0] != '9')
		{
			cout << "answer";
			return;
		}
	}

	if (c[3] != '8')
	{
		if (c[3] != '9')
		{
			cout << "answer";
			return;
		}
	}

	if (c[1] != c[2])
		cout << "answer";

	else
		cout << "ignore";
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