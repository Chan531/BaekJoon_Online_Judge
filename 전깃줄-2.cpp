#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, a, b, num, index, cnt = 0;
vector<pair<int, int>> wire;
vector<int> store, idx(100001), ans;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		wire.push_back({ a,b });
	}
}

void solution()
{
	sort(wire.begin(), wire.end());
	store.push_back(wire[0].second);
	idx[0] = 1;
	for (int i = 1; i < n; i++)
	{
		num = wire[i].second;
		if (store.back() < num)
		{
			store.push_back(num);
			idx[i] = store.size();
		}
		else
		{
			index = lower_bound(store.begin(), store.end(), num) - store.begin();
			store[index] = num;
			idx[i] = index + 1;
		}
	}
	cout << n - store.size() << '\n';
	for (int i = n - 1; i >= 0; i--)
	{
		if (store.size() - cnt == idx[i])
			cnt++;
		else
			ans.push_back(wire[i].first);
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] << '\n';
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