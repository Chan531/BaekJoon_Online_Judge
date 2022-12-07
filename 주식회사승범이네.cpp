#include <iostream>
#include <vector>
#define N 100001

using namespace std;

int n, m, idx, s[N], e[N], seg[N * 4], lazy[4 * N];
vector<int> sub[N];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int boss;
		cin >> boss;

		if (i != 1)
			sub[boss].push_back(i);
	}
}

void dfs(int node)
{
	s[node] = ++idx;

	for (auto i : sub[node])
		dfs(i);

	e[node] = idx;
}

void lazycheck(int start, int end, int node)
{
	if (lazy[node])
	{
		if (start == end)
			seg[node] += lazy[node];

		else
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		lazy[node] = 0;
	}
}

void update(int start, int end, int left, int right, int val, int node)
{
	lazycheck(start, end, node);

	if (start > right || end < left)
		return;

	if (start >= left && end <= right)
	{
		lazy[node] += val;
		return;
	}

	int mid = (start + end) / 2;

	update(start, mid, left, right, val, node * 2);
	update(mid + 1, end, left, right, val, node * 2 + 1);
}

void output(int start, int end, int idx, int node)
{
	lazycheck(start, end, node);

	if (start > idx || end < idx)
		return;

	if (start == idx && start == end)
	{
		cout << seg[node] << '\n';
		return;
	}

	int mid = (start + end) / 2;

	output(start, mid, idx, node * 2);
	output(mid + 1, end, idx, node * 2 + 1);
}

void solution()
{
	// 오일러 경로 테크닉을 통한 세그먼트 트리 인덱스 설정
	dfs(1);

	while (m--)
	{
		int q, i, w;
		cin >> q;

		if (q == 1)
		{
			cin >> i >> w;
			update(1, n, s[i], e[i], w, 1);
		}

		else
		{
			cin >> i;
			output(1, n, s[i], 1);
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