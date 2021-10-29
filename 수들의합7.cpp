#include <iostream>
#include <vector>

using namespace std;

vector<long long> v(1000001), tree(2097153);

long long getnumsum(int start, int end, int node, int left, int right)
{
	if (start > right || end < left)
		return 0;

	if (start >= left && end <= right)
		return tree[node];

	int mid = (start + end) / 2;

	return getnumsum(start, mid, node * 2, left, right) + getnumsum(mid + 1, end, node * 2 + 1, left, right);
}

void modify(int start, int end, int node, int index, long long change)
{
	if (start > index || end < index)
		return;
	
	tree[node] += change;

	if (start == end)
		return;
	
	int mid = (start + end) / 2;

	modify(start, mid, node * 2, index, change);
	modify(mid + 1, end, node * 2 + 1, index, change);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, a, b;
	long long c;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		if (a)
		{
			modify(0, n - 1, 1, b - 1, c - v[b - 1]);
			v[b - 1] = c;
		}
		else
			b < c ? cout << getnumsum(0, n - 1, 1, b - 1, c - 1) << '\n' : cout << getnumsum(0, n - 1, 1, c - 1, b - 1) << '\n';
	}
	return 0;
}