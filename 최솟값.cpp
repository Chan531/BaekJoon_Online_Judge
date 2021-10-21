#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v(100001), tree(262145);

void setmin(int start, int end, int node)
{
	if (start == end)
	{
		tree[node] = v[start];
		return;
	}

	int mid = (start + end) / 2;

	setmin(start, mid, node * 2);
	setmin(mid + 1, end, node * 2 + 1);

	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int searchmin(int start, int end, int node, int left, int right, int mi)
{
	if (start > right || end < left)
		return 1000000001;

	if (start >= left && end <= right)
	{
		if (tree[node] < mi)
			mi = tree[node];
		return mi;
	}

	int mid = (start + end) / 2;

	return mi = min(searchmin(start, mid, node * 2, left, right, mi) ,searchmin(mid + 1, end, node * 2 + 1, left, right, mi));
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
	setmin(0, n - 1, 1);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		cout << searchmin(0, n - 1, 1, a - 1, b - 1, 1000000001) << '\n';
	}
	return 0;
}