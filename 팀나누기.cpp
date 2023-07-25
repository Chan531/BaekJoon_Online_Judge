#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[4];

void input()
{
	for (int i = 0; i < 4; i++) cin >> arr[i];
}

void solution()
{
	sort(arr, arr + 4);
	cout << abs(arr[0] - arr[1] - arr[2] + arr[3]);
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