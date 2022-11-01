#include <iostream>
#define N 1000000

using namespace std;

int n, arr[N], seg[N * 4];
long long ans;

void input()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

long long check(int start, int end, int left, int right, int node)
{
	if (start > right || end < left)
		return 0;

	if (start >= left && end <= right)
		return seg[node];

	int mid = (start + end) / 2;

	return check(start, mid, left, right, node * 2) + check(mid + 1, end, left, right, node * 2 + 1);
}

void add(int start, int end, int node, int idx)
{
	if (start > idx || end < idx)
		return;

	if (start == idx && end == idx)
	{
		seg[node]++;
		return;
	}

	int mid = (start + end) / 2;

	add(start, mid, node * 2, idx);
	add(mid + 1, end, node * 2 + 1, idx);

	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		ans += check(1, n, arr[i], n, 1);
		add(1, n, 1, arr[i]);
	}

	cout << ans;
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