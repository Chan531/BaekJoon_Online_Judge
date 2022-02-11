// 2021.12.07
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n, num;
	vector<int> arr, ans, ansindex(1000000), realans;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		if (ans.empty() || ans.back() < arr[i])
		{
			ans.push_back(arr[i]);
			ansindex[i] = ans.size();
		}
		else
		{
			int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
			ans[index] = arr[i];
			ansindex[i] = index + 1;
		}
	}
	cout << ans.size() << '\n';
	for (int i = n - 1; i >= 0; i--)
	{
		if (ansindex[i] == ans.size() - realans.size())
			realans.push_back(arr[i]);

		if (ans.size() == realans.size())
			break;
	}
	for (int i = realans.size() - 1; i >= 0; i--)
		cout << realans[i] << ' ';
	return 0;
}

// 2022.02.11 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, num, cnt;
vector<int> arr, store, ans, record(1000000);

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
	for (int i = 0; i < n; i++)
	{
		if (store.empty() || store.back() < arr[i])
		{
			store.push_back(arr[i]);
			record[i] = store.size();
			continue;
		}

		int idx = lower_bound(store.begin(), store.end(), arr[i]) - store.begin();
		store[idx] = arr[i];
		record[i] = idx + 1;
	}

	cnt = store.size();

	for (int i = n - 1; i >= 0; i--)
	{
		if (record[i] == cnt - ans.size())
			ans.push_back(arr[i]);

		if (store.size() == ans.size())
			break;
	}

	cout << cnt << '\n';
	for (int i = cnt - 1; i >= 0; i--)
		cout << ans[i] << ' ';
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