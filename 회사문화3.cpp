#include <iostream>
#include <vector>
#define N 100001

using namespace std;

int n, m, idx, s[N], e[N], seg[4 * N];
vector<int> sub[N];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int v;
		cin >> v;

		if (i != 1)
			sub[v].push_back(i);
	}
}

// 오일러 경로 테크닉을 통한 세그먼트트리 인덱스 지정
void dfs(int node)
{
	s[node] = ++idx;

	for (auto i : sub[node])
		dfs(i);

	e[node] = idx;
}

void update(int start, int end, int idx, int val, int node)
{
	if (start > idx || end < idx)
		return;

	if (start == end && start == idx)
	{
		seg[node] += val;
		return;
	}

	int mid = (start + end) / 2;

	update(start, mid, idx, val, node * 2);
	update(mid + 1, end, idx, val, node * 2 + 1);

	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int output(int start, int end, int left, int right, int node)
{
	if (start > right || end < left)
		return 0;

	if (start >= left && end <= right)
		return seg[node];

	int mid = (start + end) / 2;

	return output(start, mid, left, right, node * 2) + output(mid + 1, end, left, right, node * 2 + 1);
}

void solution()
{
	dfs(1);

	// 상사의 칭찬 정도는 부하가 받은 칭찬 정도의 합이다.
	while (m--)
	{
		int q, i, w;
		cin >> q;

		if (q == 1)
		{
			cin >> i >> w;
			update(1, n, s[i], w, 1);
		}

		else
		{
			cin >> i;
			cout << output(1, n, s[i], e[i], 1) << '\n';
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