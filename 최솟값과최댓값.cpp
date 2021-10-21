#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v(100001);
vector<pair<int, int>> tree(262145);
int le, la;

void setm(int start, int end, int node)
{
	if (start == end)
	{
		tree[node].first = v[start];
		tree[node].second = v[start];
		return;
	}
	int mid = (start + end) / 2;

	setm(start, mid, node * 2); 
	setm(mid + 1, end, node * 2 + 1);

	tree[node].first = min(tree[node * 2].first, tree[node * 2 + 1].first);
	tree[node].second = max(tree[node * 2].second, tree[node * 2 + 1].second);
}

void searchm(int start, int end, int node, int left, int right)
{
	if (start > right || end < left)
		return;

	if (start >= left && end <= right)
	{
		if (tree[node].first < le)
			le = tree[node].first;
		if (tree[node].second > la)
			la = tree[node].second;
		return;
	}

	int mid = (start + end) / 2;

	searchm(start, mid, node * 2, left, right);
	searchm(mid + 1, end, node * 2 + 1, left, right);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, num, a, b;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v[i] = num;
	}
	setm(0, n - 1, 1);
	for (int i = 0; i < m; i++)
	{
		le = 1000000001;
		la = 1;
		cin >> a >> b;
		searchm(0, n - 1, 1, a - 1, b - 1);
		cout << le << ' ' << la << '\n';
	}
	return 0;
}