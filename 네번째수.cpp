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

	if (arr[1] - arr[0] == arr[2] - arr[1])
		cout << arr[2] + arr[2] - arr[1];

	else if (arr[1] - arr[0] > arr[2] - arr[1])
		cout << arr[0] + arr[2] - arr[1];

	else
		cout << arr[1] + arr[1] - arr[0];
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