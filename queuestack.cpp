#include <iostream>
#include <vector>

using namespace std;

int n, m, type[101010], num[101010], arr[101010];
vector<int> ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++) cin >> type[i];
	for (int i = 0; i < n; i++) cin >> num[i];

	cin >> m;
	for (int i = 0; i < m; i++) cin >> arr[i];
}

void solution()
{
	for (int i = n - 1; i >= 0; i--)
		if (!type[i] && ans.size() != m)
			ans.push_back(num[i]);

	for (int i = 0; i < m; i++)
	{
		if (ans.size() == m) break;
		ans.push_back(arr[i]);
	}

	for (auto i : ans) cout << i << ' ';
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