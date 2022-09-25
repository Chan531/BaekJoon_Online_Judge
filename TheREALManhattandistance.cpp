#include <iostream>
#include <cmath>

using namespace std;

int arr[6];

void input()
{
	for (int i = 0; i < 6; i++)
		cin >> arr[i];
}

void solution()
{
	cout << abs(arr[0] - arr[3]) + abs(arr[1] - arr[4]) + arr[2] + arr[5] << '\n';
}

void solve()
{
	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		input();
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