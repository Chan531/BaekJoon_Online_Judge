#include <iostream>
#include <numeric>

using namespace std;

int arr[10];

void input()
{
	for (int i = 0; i < 10; i++)
		cin >> arr[i];
}

void solution()
{
	int sum = accumulate(arr, arr + 10, 0);

	for (int i = 0; i < 10; i++)
	{
		if (sum - arr[i] == arr[i])
		{
			cout << arr[i];
			break;
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