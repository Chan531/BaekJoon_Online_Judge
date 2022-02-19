#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, num, h = 0, ans = 0;
vector<int> arr;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
}

void solution()
{
	num = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (num < arr[i])
			h += arr[i] - num;

		if (num >= arr[i] || i == n - 1)
		{
			ans = max(h, ans);
			h = 0;
		}

		num = arr[i];
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
	cout.tie(NULL);

	solve();
	return 0;
}