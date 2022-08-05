#include <iostream>
#define Y 1000001

using namespace std;

int N, Q;
long long arr[Y], tree[Y * 4];

void input()
{
	cin >> N >> Q;
}

void updatetree(int start, int end, int node, int idx, long long val)
{
	if (start > idx || end < idx)
		return;

	tree[node] += val;

	if (start == end && start == idx)
		return;

	int mid = (start + end) / 2;

	updatetree(start, mid, node * 2, idx, val);
	updatetree(mid + 1, end, node * 2 + 1, idx, val);
}

long long output(int start, int end, int left, int right, int node)
{
	if (start > right || end < left)
		return 0;

	if (start >= left && end <= right)
		return tree[node];

	int mid = (start + end) / 2;

	return output(start, mid, left, right, node * 2) + output(mid + 1, end, left, right, node * 2 + 1);
}

void solution()
{
	int c, p, q;

	while (Q--)
	{
		cin >> c >> p >> q;

		if (c == 1)
			updatetree(1, N, 1, p, q);

		else
			cout << output(1, N, p, q, 1) << '\n';
	}
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
	cout.tie(NULL);

	solve();
	return 0;
}