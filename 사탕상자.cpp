#include <iostream>
#define N 1000000

using namespace std;

int n, seg[N * 4];

void input()
{
	cin >> n;
}

void q1(int start, int end, int rank, int node)
{
	if (start == end)
	{
		seg[node]--;
		cout << start << '\n';
		return;
	}

	int mid = (start + end) / 2;

	if (seg[node * 2] >= rank)
		q1(start, mid, rank, node * 2);

	else
		q1(mid + 1, end, rank - seg[node * 2], node * 2 + 1);

	seg[node] = seg[node * 2] + seg[node * 2 + 1];	
}

void q2(int start, int end, int idx, int cnt, int node)
{
	if (start > idx || end < idx)
		return;

	if (start == idx && start == end)
	{
		seg[node] += cnt;
		return;
	}

	int mid = (start + end) / 2;

	q2(start, mid, idx, cnt, node * 2);
	q2(mid + 1, end, idx, cnt, node * 2 + 1);

	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

void solution()
{
	while (n--)
	{
		int a, b, c;
		cin >> a;

		if (a == 1)
		{
			cin >> b;
			q1(1, N, b, 1);
		}

		else
		{
			cin >> b >> c;
			q2(1, N, b, c, 1);
		}
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