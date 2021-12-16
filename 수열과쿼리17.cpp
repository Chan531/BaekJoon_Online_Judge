#include <iostream>
#include <vector>
#include <algorithm>
#define MAXV 1000000001

using namespace std;
vector<int> arr, tree(262144);

int setsection(int start, int end, int node)
{
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = min(setsection(start, mid, node * 2), setsection(mid + 1, end, node * 2 + 1));
}

int minvalue(int start, int end, int left, int right, int node)
{
	if (end < left || start > right)
		return MAXV;

	if (end <= right && start >= left)
		return tree[node];

	int mid = (start + end) / 2;

	return min(minvalue(start, mid, left, right, node * 2), minvalue(mid + 1, end, left, right, node * 2 + 1));
}

void changevalue(int start, int end, int index, int value, int node)
{
	if (end < index || start > index)
		return;

	if (start == index && end == index)
	{
		tree[node] = value;
		return;
	}

	int mid = (start + end) / 2;

	changevalue(start, mid, index, value, node * 2);
	changevalue(mid + 1, end, index, value, node * 2 + 1);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num, m, a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	setsection(0, n - 1, 1);
	cin >> m;
	while (m--)
	{
		cin >> num >> a >> b;
		if (num == 1)
		{
			changevalue(0, n - 1, a - 1, b, 1);
			arr[a - 1] = b;
		}
		else
			cout << minvalue(0, n - 1, a - 1, b - 1, 1) << '\n';
	}
	return 0;
}