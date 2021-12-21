#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000001

using namespace std;
vector<int> prog;
vector<pair<int, int>> tree(262144);

void setsection(int start, int end, int node)
{
	if (start == end)
	{
		tree[node].first = prog[start];
		tree[node].second = start;
		return;
	}

	int mid = (start + end) / 2;

	setsection(start, mid, node * 2);
	setsection(mid + 1, end, node * 2 + 1);

	if (tree[2 * node].first <= tree[2 * node + 1].first)
	{
		tree[node].first = tree[2 * node].first;
		tree[node].second = tree[2 * node].second;
	}
	else
	{
		tree[node].first = tree[2 * node + 1].first;
		tree[node].second = tree[2 * node + 1].second;
	}
}

int findnum(int start, int end, int left, int right, int node)
{
	if (start > right || end < left)
		return -1;

	if (start >= left && end <= right)
		return tree[node].second;

	int mid = (start + end) / 2;

	int le = findnum(start, mid, left, right, node * 2);
	int ri = findnum(mid + 1, end, left, right, node * 2 + 1);

	if (le == -1)
		return ri;

	else if (ri == -1)
		return le;

	if (prog[le] <= prog[ri])
		return le;
	else
		return ri;
}

void changenum(int start, int end, int node, int index, int value)
{
	if (start > index || end < index)
		return;

	if (start == index && end == index)
	{
		tree[node].first = value;
		return;
	}

	int mid = (start + end) / 2;

	changenum(start, mid, node * 2, index, value);
	changenum(mid + 1, end, node * 2 + 1, index, value);

	if (tree[2 * node].first <= tree[2 * node + 1].first)
	{
		tree[node].first = tree[2 * node].first;
		tree[node].second = tree[2 * node].second;
	}
	else
	{
		tree[node].first = tree[2 * node + 1].first;
		tree[node].second = tree[2 * node + 1].second;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num, m, a, b;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		prog.push_back(num);
	}
	setsection(0, n - 1, 1);
	cin >> m;
	while (m--)
	{
		cin >> num >> a >> b;
		if (num == 1)
		{
			changenum(0, n - 1, 1, a - 1, b);
			prog[a - 1] = b;
		}
		else
			cout << findnum(0, n - 1, a - 1, b - 1, 1) + 1 << '\n';
	}
	return 0;
}