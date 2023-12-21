#include <iostream>
#include <algorithm>
#include <vector>
#define N 101010

using namespace std;

int n, m, id, par[N];
vector<int> con[N], v;
vector<vector<int>> scc;
bool check[N];

void input()
{
	cin >> n >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		con[a].push_back(b);
	}
}

void insert(int node)
{
	vector<int> temp;

	while (1)
	{
		temp.push_back(v.back());
		v.pop_back();
		check[temp.back()] = 1;

		if (temp.back() == node)
			break;
	}

	sort(temp.begin(), temp.end());
	scc.push_back(temp);
}

int dfs(int node)
{
	v.push_back(node);
	par[node] = ++id;
	int root = par[node];

	for (auto i : con[node])
	{
		if (!par[i])	// 방문하지 않은 노드
			root = min(root, dfs(i));

		else if (!check[i])	// 스택 안에서 처리 중인 노드
			root = min(root, par[i]);
	}

	if (root == par[node])
		insert(node);

	return root;
}

void print()
{
	cout << scc.size() << '\n';

	for (auto i : scc)
	{
		for (auto j : i)
			cout << j << ' ';

		cout << -1 << '\n';
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		if (check[i])
			continue;

		dfs(i);
	}

	sort(scc.begin(), scc.end());
	print();
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