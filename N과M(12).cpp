#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, num;
vector<int> arr, ans;

void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
}

void backtrack(int i, int cnt)
{
	if (cnt == m)
	{
		for (auto k : ans)
			cout << k << ' ';
		cout << '\n';
		return;
	}

	for (int j = i; j < n; j++)
	{
		if (j > 0 && arr[j] == arr[j - 1])
			continue;
		ans.push_back(arr[j]);
		backtrack(j, cnt + 1);
		ans.pop_back();
	}
}

void solution()
{
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && arr[i] == arr[i - 1])
			continue;
		ans.push_back(arr[i]);
		backtrack(i, 1);
		ans.pop_back();
	}
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