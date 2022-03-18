#include <iostream>
#define N 100001

using namespace std;

int n, k, a, b, arr[N], tree[N * 4];
char c;

void input()
{
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

int setsegtree(int start, int end, int node)
{
	if (start == end)
		return tree[node] = (arr[start] > 0) ? 1 : ((arr[start] < 0) ? -1 : 0);

	int mid = (start + end) / 2;

	return tree[node] = setsegtree(start, mid, node * 2) * setsegtree(mid + 1, end, node * 2 + 1);
}

void updatesegtree(int start, int end, int node, int index, int value)
{
	if (start > index || end < index)
		return;

	if (start == index && end == index)
	{
		arr[start] = value;
		tree[node] = (arr[start] > 0) ? 1 : ((arr[start] < 0) ? -1 : 0);
		return;
	}

	int mid = (start + end) / 2;

	updatesegtree(start, mid, node * 2, index, value);
	updatesegtree(mid + 1, end, node * 2 + 1, index, value);

	tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int printsegtree(int start, int end, int node, int left, int right)
{
	if (start > right || end < left)
		return 1;

	if (start >= left && end <= right)
		return tree[node];

	int mid = (start + end) / 2;

	return printsegtree(start, mid, node * 2, left, right) * printsegtree(mid + 1, end, node * 2 + 1, left, right);
}

void solution()
{
	string ans = "";
	setsegtree(0, n - 1, 1);
	while (k--)
	{
		cin >> c >> a >> b;                  // 명령, 위치, 숫자
		if (c == 'C')
			updatesegtree(0, n - 1, 1, a - 1, b);
		else
		{
			int t = printsegtree(0, n - 1, 1, a - 1, b - 1);
			(t > 0) ? ans += '+' : ((t < 0) ? ans += '-' : ans += '0');
		}
	}
	cout << ans << '\n';
}

void solve()
{
	while (cin >> n >> k)
	{
		input();
		solution();
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