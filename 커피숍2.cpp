#include <iostream>
#include <vector>

using namespace std;

int n, q, x, y, a;
long long num, b;

vector<long long> tree, segmenttree(400000);

long long makesegmenttree(int start, int end, int node)
{
	if (start == end)
		return segmenttree[node] = tree[start];

	int mid = (start + end) / 2;

	return segmenttree[node] = makesegmenttree(start, mid, node * 2) + makesegmenttree(mid + 1, end, node * 2 + 1);
}

long long sectionsum(int start, int end, int left, int right, int node)
{
	if (start > right || end < left)
		return 0;

	if (start >= left && end <= right)
		return segmenttree[node];

	int mid = (start + end) / 2;

	return sectionsum(start, mid, left, right, node * 2) + sectionsum(mid + 1, end, left, right, node * 2 + 1);
}

void updatesegmenttree(int start, int end, int node, int index, long long value)
{
	if (start > index || end < index)
		return;

	if (start == index && end == index)
	{
		segmenttree[node] = value;
		return;
	}

	int mid = (start + end) / 2;

	updatesegmenttree(start, mid, node * 2, index, value);
	updatesegmenttree(mid + 1, end, node * 2 + 1, index, value);

	segmenttree[node] = segmenttree[node * 2] + segmenttree[node * 2 + 1];
}

void solve()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		tree.push_back(num);
	}
	makesegmenttree(0, n - 1, 1);
	while (q--)
	{
		cin >> x >> y >> a >> b;
		x < y ? cout << sectionsum(0, n - 1, x - 1, y - 1, 1) << '\n' : cout << sectionsum(0, n - 1, y - 1, x - 1, 1) << '\n';
		updatesegmenttree(0, n - 1, 1, a - 1, b);
		tree[a - 1] = b;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
	return 0;
}