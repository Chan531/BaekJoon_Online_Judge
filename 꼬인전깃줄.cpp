#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, num, idx;
vector<int> arr, lis;

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
	lis.push_back(arr[0]);

	for (int i = 1; i < n; i++)
	{
		if (lis.back() <= arr[i])
		{
			lis.push_back(arr[i]);
			continue;
		}

		idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
		lis[idx] = arr[i];
	}

	cout << n - lis.size();
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