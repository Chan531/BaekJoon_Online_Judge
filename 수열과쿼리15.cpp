#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	int val, idx;
};

int n, m, com, idx, val, arr[100000];
node segmenttree[400000];

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void setsegmenttree(int start, int end, int node)
{
	if (start == end)
	{
		segmenttree[node] = { arr[start], start + 1 };
		return;
	}

	int mid = (start + end) / 2;

	setsegmenttree(start, mid, node * 2);
	setsegmenttree(mid + 1, end, node * 2 + 1);

	segmenttree[node * 2].val <= segmenttree[node * 2 + 1].val ? segmenttree[node] = segmenttree[node * 2] : segmenttree[node] = segmenttree[node * 2 + 1];
	return;
}

void update(int start, int end, int node, int idx, int val)
{
	if (start > idx || end < idx)
		return;

	if (start == idx && end == idx)
	{
		arr[idx] = val;
		segmenttree[node] = { val, idx + 1 };
		return;
	}

	int mid = (start + end) / 2;

	update(start, mid, node * 2, idx, val);
	update(mid + 1, end, node * 2 + 1, idx, val);

	segmenttree[node * 2].val <= segmenttree[node * 2 + 1].val ? segmenttree[node] = segmenttree[node * 2] : segmenttree[node] = segmenttree[node * 2 + 1];
	return;
}

void solve()
{
	input();
	setsegmenttree(0, n - 1, 1);
	cin >> m;
	while (m--)
	{
		cin >> com;
		if (com == 1)
		{
			cin >> idx >> val;
			update(0, n - 1, 1, idx - 1, val);
		}
		else
			cout << segmenttree[1].idx << '\n';
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