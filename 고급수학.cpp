#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];
string ans;

void input()
{
	for (int i = 0; i < 3; i++) cin >> arr[i];
}

void solution()
{
	sort(arr, arr + 3);

	if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2])
		ans = "yes";
	else ans = "no";
}

void solve()
{
	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++)
	{
		input();
		solution();
		cout << "Scenario #" << i << ":\n" << ans << "\n\n";
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	return 0;
}