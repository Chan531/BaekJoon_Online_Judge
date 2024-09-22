#include <iostream>

using namespace std;

int n, arr[1010], t, ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		t ^= arr[i];
	}
}

void solution()
{
	if (!t)
	{
		cout << 0;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		int k = t ^ arr[i];
		
		if (arr[i] > k)
			ans++;
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