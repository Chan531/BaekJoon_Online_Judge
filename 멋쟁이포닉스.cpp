#include <iostream>
#include <algorithm>

using namespace std;

int arr[3][2], ans;

void input()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			cin >> arr[i][j];
}

void solution()
{
	int n = min({ arr[0][1], arr[1][0], arr[2][1] });
	int m = min({ arr[0][0], arr[1][1], arr[2][0] });
	if (n > m) ans = m * 2 + 1;
	else if (n == m) ans = n * 2;
	else ans = n * 2 + 1;
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