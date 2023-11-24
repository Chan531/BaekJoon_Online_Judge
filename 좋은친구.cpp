#include <iostream>
#include <vector>
#include <algorithm>
#define N 22
#define ll long long

using namespace std;

int n, k;
vector<int> arr[N];
ll ans;

void input()
{
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		arr[s.length()].push_back(i);
	}
}

void solution()
{
	for (int i = 2; i < N; i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			int tar = arr[i][j] + k;
			int idx = lower_bound(arr[i].begin(), arr[i].end(), tar) - arr[i].begin();

			if (idx == arr[i].size() || arr[i][idx] > tar)
				idx--;

			ans += idx - j;
		}
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