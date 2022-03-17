#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, a, b, c, d;
long long ans = 0;
vector<int> arr[4], arr1, arr2;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c >> d;
		arr[0].push_back(a);
		arr[1].push_back(b);
		arr[2].push_back(c);
		arr[3].push_back(d);
	}
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr1.push_back(arr[0][i] + arr[1][j]);
			arr2.push_back(arr[2][i] + arr[3][j]);
		}
	}
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	for (int i = 0; i < n * n; i++)
	{
		int num = -arr1[i];
		int minidx = lower_bound(arr2.begin(), arr2.end(), num) - arr2.begin();
		int maxidx = upper_bound(arr2.begin(), arr2.end(), num) - arr2.begin();
		ans += maxidx - minidx;
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