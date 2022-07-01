#include <iostream>

using namespace std;

int n, num, arr[1000002], ans;

void input()
{
	cin >> n;

	while (n--)
	{
		cin >> num;

		if (arr[num + 1])
			arr[num + 1]--;

		arr[num]++;
	}
}

void solution()
{
	for (int i = 1; i <= 1000000; i++)
		if (arr[i])
			ans += arr[i];

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
	cout.tie(NULL);

	solve();
	return 0;
}