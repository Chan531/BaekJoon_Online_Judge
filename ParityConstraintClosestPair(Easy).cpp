#include <iostream>
#include <algorithm>
#define N 1000000001

using namespace std;

int n, arr[505050], minodd = N, mineven = N, oddans = 2 * N, evenans = 2 * N;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
}

void solution()
{
	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 && minodd == N)
			minodd = arr[i];

		if (!(arr[i] % 2) && mineven == N)
			mineven = arr[i];

		if (minodd != N && mineven != N)
			break;
	}

	for (int i = 0; i < n; i++)
	{
		// Ȧ��
		if (arr[i] % 2)
		{
			// Ȧ�� - Ȧ��
			if (minodd != N && minodd < arr[i])
				evenans = min(evenans, arr[i] - minodd);

			// Ȧ�� - ¦��
			if (mineven != N && mineven < arr[i])
				oddans = min(oddans, arr[i] - mineven);

			minodd = arr[i];
		}

		// ¦��
		else
		{
			// ¦�� - Ȧ��
			if (minodd != N && minodd < arr[i])
				oddans = min(oddans, arr[i] - minodd);

			// ¦�� - ¦��
			if (mineven != N && mineven < arr[i])
				evenans = min(evenans, arr[i] - mineven);

			mineven = arr[i];
		}
	}

	if (oddans == 2 * N)
		oddans = -1;

	if (evenans == 2 * N)
		evenans = -1;

	cout << evenans << ' ' << oddans;
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