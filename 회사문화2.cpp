#include <iostream>
#include <vector>
#define N 100001

using namespace std;

int n, m, cnt;
int s[N], e[N], tree[N * 4], lazy[N * 4];
vector<int> sub[N];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;

		// 사장 pass
		if (num == -1)
			continue;

		sub[num].push_back(i);
	}
}

// 오일러 경로 테크닉을 통한 idx의 구간 설정
void dfs(int idx)
{
	s[idx] = ++cnt;

	for (int i = 0; i < sub[idx].size(); i++)
		dfs(sub[idx][i]);

	e[idx] = cnt;
}

void lazycheck(int start, int end, int node)
{
	if (lazy[node])
	{
		tree[node] += lazy[node];

		if (start != end)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}

		lazy[node] = 0;
	}
}

void update(int start, int end, int left, int right, int node, int val)
{
	lazycheck(start, end, node);

	if (start > right || end < left)
		return;

	if (start >= left && end <= right)
	{
		tree[node] += val;

		if (start != end)
		{
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}

		return;
	}

	int mid = (start + end) / 2;

	update(start, mid, left, right, node * 2, val);
	update(mid + 1, end, left, right, node * 2 + 1, val);

	tree[node] += tree[node * 2] + tree[node * 2 + 1];
}

int output(int start, int end, int node, int idx)
{
	lazycheck(start, end, node);

	if (start > idx || end < idx)
		return 0;
	
	if (start == idx && end == idx)
		return tree[node];

	int mid = (start + end) / 2;

	return output(start, mid, node * 2, idx) + output(mid + 1, end, node * 2 + 1, idx);
}

void solution()
{
	dfs(1);

	int q, i, w;

	while (m--)
	{
		cin >> q;

		// update
		if (q == 1)
		{
			cin >> i >> w;
			update(0, n, s[i], e[i], 1, w);
		}

		// output
		else
		{
			cin >> i;
			cout << output(0, n, 1, s[i]) << '\n';
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