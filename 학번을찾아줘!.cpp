#include <iostream>

using namespace std;

int n, arr[5], ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	if (arr[0] > arr[2])
		ans += (arr[0] - arr[2]) * 508;

	else
		ans += (arr[2] - arr[0]) * 108;

	if (arr[1] > arr[3])
		ans += (arr[1] - arr[3]) * 212;

	else
		ans += (arr[3] - arr[1]) * 305;

	if (n == 5)
		ans += arr[4] * 707;

	cout << ans * 4763;

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