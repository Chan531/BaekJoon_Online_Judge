#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, num;
vector<int> arr, ans;

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
	ans.push_back(arr[0]);

	for (int i = 1; i < n; i++)
	{
		int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();

		if (idx < ans.size())
			ans[idx] = arr[i];
		else
			ans.push_back(arr[i]);
	}
	cout << ans.size();
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