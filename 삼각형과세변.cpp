#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];

void input()
{
	for (int i = 0; i < 3; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + 3);

	if (arr[2] >= arr[0] + arr[1])
	{
		cout << "Invalid\n";
		return;
	}

	if (arr[0] == arr[1] && arr[1] == arr[2])
	{
		cout << "Equilateral\n";
		return;
	}

	if (arr[1] == arr[2])
	{
		cout << "Isosceles\n";
		return;
	}

	cout << "Scalene\n";
}

void solve()
{
	while (1)
	{
		input();

		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break;

		solution();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}