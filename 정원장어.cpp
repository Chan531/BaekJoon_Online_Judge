#include <iostream>
#include <vector>
#include <algorithm>
#define N 300000

using namespace std;

int n, arr[N], ans[N];
vector<int> lis;
char dir[N];

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> dir[i];

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		if (dir[i] == 'R')
		{
			ans[i] = lis.size();
			continue;
		}

		if (lis.empty() || lis.back() < arr[i])
		{
			lis.push_back(arr[i]);
			ans[i] = lis.size();
			continue;
		}

		int index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
		lis[index] = min(lis[index], arr[i]);

		ans[i] = lis.size();
	}

	lis.clear();

	for (int i = n - 1; i >= 0; i--)
	{
		if (dir[i] == 'L')
		{
			ans[i] += lis.size();
			continue;
		}

		if (lis.empty() || lis.back() < arr[i])
		{
			lis.push_back(arr[i]);
			ans[i] = lis.size();
			continue;
		}

		int index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
		lis[index] = min(lis[index], arr[i]);

		ans[i] += lis.size();
	}

	cout << n - *max_element(ans, ans + n);
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