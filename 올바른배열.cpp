#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, num, ans = 4;
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
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
	{
		int idx = i + 1, cnt = 4;
		for (int j = arr[i] + 1; j <= arr[i] + 4; j++)
		{
			if (idx < n && arr[idx] == j)
			{
				idx++;
				cnt--;
			}
		}
		ans = min(ans, cnt);
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