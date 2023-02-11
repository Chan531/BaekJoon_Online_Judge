#include <iostream>

using namespace std;

int n, arr[9];

void input()
{
	cin >> n;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int m;
			cin >> m;

			if (m > arr[i])
				arr[i] = m;
		}
	}
}

void checkindex(int i)
{
	if (i == 0)
		cout << "PROBRAIN";

	else if (i == 1)
		cout << "GROW";

	else if (i == 2)
		cout << "ARGOS";

	else if (i == 3)
		cout << "ADMIN";

	else if (i == 4)
		cout << "ANT";

	else if (i == 5)
		cout << "MOTION";

	else if (i == 6)
		cout << "SPG";

	else if (i == 7)
		cout << "COMON";

	else
		cout << "ALMIGHTY";
}

void solution()
{
	int maxval = 0;
	int index = 0;

	for (int i = 0; i < 9; i++)
	{
		if (maxval < arr[i])
		{
			maxval = arr[i];
			index = i;
		}
	}

	checkindex(index);
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
	cout.tie(NULL);

	solve();
	return 0;
}