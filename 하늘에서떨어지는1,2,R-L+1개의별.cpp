#include <iostream>
#define N 100001

using namespace std;

struct node {
	// val -> left들 모음, cnt -> 업데이트 횟수
	// i번째 점에 별이 떨어진다면 그 별의 개수는 i - left + 1이다.
	// 업데이트를 진행할 때마다 left를 val에 더해주고 cnt에 1을 더해준다.
	// 최종적으로 처리할 때 arr[i]의 값에는 (i + 1) * cnt - val을 해줘야한다.
	long long val, cnt;
};

int n, q;
long long arr[N];
node segmenttree[N * 4];

void input()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

// 느리게 갱신되는 세그먼트 트리
void lazyprop(int start, int end, int node)
{
	if (segmenttree[node].cnt == 0)
		return;

	long long val = segmenttree[node].val;
	long long cnt = segmenttree[node].cnt;

	if (start != end)
	{
		// 느리게 갱신
		segmenttree[node * 2].val += val;
		segmenttree[node * 2].cnt += cnt;
		segmenttree[node * 2 + 1].val += val;
		segmenttree[node * 2 + 1].cnt += cnt;
	}

	if (start == end)
		arr[start] += (start + 1) * cnt - val;

	// 값 초기화
	segmenttree[node].val = 0;
	segmenttree[node].cnt = 0;
}

void updatetree(int start, int end, int node, int left, int right)
{
	// 사전에 처리해야할 작업이 있나 확인
	lazyprop(start, end, node);

	// 범위에 포함 x라면 pass
	if (start > right || end < left)
		return;

	// 범위에 속한다면 처리
	if (left <= start && end <= right)
	{
		segmenttree[node].val += left;
		segmenttree[node].cnt++;

		return;
	}

	int mid = (start + end) / 2;

	updatetree(start, mid, node * 2, left, right);
	updatetree(mid + 1, end, node * 2 + 1, left, right);
}

long long getval(int start, int end, int node, int idx)
{
	// 사전에 처리해야할 작업이 있나 확인
	lazyprop(start, end, node);

	if (start > idx || end < idx)
		return 0;

	if (start == idx && end == idx)
		return arr[start];

	int mid = (start + end) / 2;

	return getval(start, mid, node * 2, idx) + getval(mid + 1, end, node * 2 + 1, idx);
}

void solution()
{
	cin >> q;

	while (q--)
	{
		int com, l, r, x;
		cin >> com;

		if (com == 1)
		{
			cin >> l >> r;
			updatetree(1, n, 1, l, r);
		}

		else
		{
			cin >> x;
			cout << getval(1, n, 1, x) << '\n';
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