#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n, m, num;
vector<int> arr, ans;
map<int, int> arrnum;

void input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
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

	for (int j = i; j < arr.size(); j++)
	{
		if (arrnum[arr[j]])
		{
			ans.push_back(arr[j]);
			arrnum[arr[j]]--;
			backtrack(j, cnt + 1);
			arrnum[arr[j]]++;
			ans.pop_back();
		}
	}
}

void solution()
{
	sort(arr.begin(), arr.end());
	for (auto i : arr)
		arrnum[i]++;
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (int i = 0; i < arr.size(); i++)
	{
		ans.push_back(arr[i]);
		arrnum[arr[i]]--;
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