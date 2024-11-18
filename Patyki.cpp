#include <iostream>
#include <algorithm>

using namespace std;

int ans, arr[3];

void input()
{
	for (int i = 0; i < 3; i++)
		cin >> arr[i];
}

void solution()
{
	sort(arr, arr + 3);

	if (arr[0] + arr[1] > arr[2])
	{
		if (arr[0] == arr[1] && arr[1] == arr[2])
			ans = 2;
		else if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2])
			ans = 1;
	}
	cout << ans;
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