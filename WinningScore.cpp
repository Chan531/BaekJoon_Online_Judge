#include <iostream>

using namespace std;

int arr[2];

void input()
{
	for (int i = 0; i < 6; i++)
	{
		int a;
		cin >> a;

		if (i % 3 == 0)
		{
			if (i / 3 == 0)
				arr[0] += a * 3;

			else
				arr[1] += a * 3;
		}

		else if (i % 3 == 1)
		{
			if (i / 3 == 0)
				arr[0] += a * 2;

			else
				arr[1] += a * 2;
		}

		else
		{
			if (i / 3 == 0)
				arr[0] += a;

			else
				arr[1] += a;
		}
	}
}

void solution()
{
	if (arr[0] > arr[1])
		cout << 'A';

	else if (arr[0] < arr[1])
		cout << 'B';

	else
		cout << 'T';
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