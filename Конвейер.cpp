#include <iostream>
#include <numeric>

using namespace std;

int n, arr[1010];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	int sum = accumulate(arr, arr + n, 0);

	if (sum < 0)
		cout << "Left";

	else if (sum == 0)
		cout << "Stay";

	else
		cout << "Right";
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