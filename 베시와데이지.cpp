#include <iostream>
#include <algorithm>
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
	int b = max(abs(arr[0] - arr[4]), abs(arr[1] - arr[5]));
	int d = abs(arr[2] - arr[4]) + abs(arr[3] - arr[5]);

	if (b < d)
		cout << "bessie";

	else if (b > d)
		cout << "daisy";

	else
		cout << "tie";
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