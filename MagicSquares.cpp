#include <iostream>

using namespace std;

int arr[4][4];

void input()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> arr[i][j];
}

void solution()
{
	int val = 0;

	for (int i = 0; i < 4; i++)
		val += arr[i][0];

	for (int i = 0; i < 4; i++)
	{
		int a = 0, b = 0;

		for (int j = 0; j < 4; j++)
		{
			a += arr[i][j];
			b += arr[j][i];
		}

		if (a != val || b != val)
		{
			cout << "not magic";
			return;
		}
	}

	cout << "magic";
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