#include <iostream>

using namespace std;

int n;

void input()
{
	cin >> n;
}

void solution()
{
	int m = n / 14;
	int k = n % 14;

	if (k == 1 || k == 13)
		cout << "baby";

	else if (k == 2 || k == 0)
		cout << "sukhwan";

	else if (k == 5)
		cout << "very";

	else if (k == 6)
		cout << "cute";

	else if (k == 9)
		cout << "in";

	else if (k == 10)
		cout << "bed";

	else if (k == 3 || k == 7 || k == 11)
	{
		cout << "tu";

		if (m < 3)
		{
			for (int i = -1; i <= m; i++)
				cout << "ru";
		}

		else
		{
			cout << "+ru*" << m + 2;
		}
	}

	else if (k == 4 || k == 8 || k == 12)
	{
		cout << "tu";

		if (m < 4)
		{
			for (int i = 0; i <= m; i++)
				cout << "ru";
		}

		else
		{
			cout << "+ru*" << m + 1;
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