#include <iostream>
#include <vector>
#include <algorithm>
#define N 101

using namespace std;

int n, arr[N], id, par[N], ans;
vector<int> con[N], v;
bool check[N];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < n; j++)
			if (s[j] == '1')
				con[i].push_back(j + 1);
	}
}

void insert(int node)
{
	int val = 1e9;

	while (1)
	{
		int temp = v.back();
		val = min(val, arr[temp]);
		v.pop_back();
		check[temp] = 1;

		if (temp == node)
			break;
	}

	ans += val;
}

int dfs(int node)
{
	par[node] = ++id;
	int root = par[node];
	v.push_back(node);

	for (auto i : con[node])
	{
		if (!par[i])
			root = min(root, dfs(i));

		else if (!check[i])
			root = min(root, par[i]);
	}

	if (root == par[node])
		insert(node);

	return root;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		if (check[i])
			continue;

		dfs(i);
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