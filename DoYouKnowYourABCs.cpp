#include <iostream>
#include <algorithm>

using namespace std;

long long arr[7];

void input()
{
	for (int i = 0; i < 7; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + 7);
	cout << arr[0] << ' ' << arr[1] << ' ' << arr[6] - arr[0] - arr[1];
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