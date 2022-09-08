#include <iostream>

using namespace std;

int d, k;

int arr[31];

void input()
{
	cin >> d >> k;
}

void solution()
{
	if (d == 3)
	{
		cout << 1 << '\n' << k - 1;
		return;
	}

	arr[2] = 1;
	arr[3] = 1;

	for (int i = 4; i <= d; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	int num = 1;

	while (1)
	{
		int a = arr[d - 1];
		int b = arr[d];

		if ((k - (a * num)) % b == 0)
		{
			cout << num << '\n' << (k - (a * num)) / b;
			break;
		}

		num++;
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
	cout.tie(NULL);

	solve();
	return 0;
}