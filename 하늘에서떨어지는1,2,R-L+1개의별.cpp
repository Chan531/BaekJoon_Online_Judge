#include <iostream>
#define N 100001

using namespace std;

struct node {
	// val -> left�� ����, cnt -> ������Ʈ Ƚ��
	// i��° ���� ���� �������ٸ� �� ���� ������ i - left + 1�̴�.
	// ������Ʈ�� ������ ������ left�� val�� �����ְ� cnt�� 1�� �����ش�.
	// ���������� ó���� �� arr[i]�� ������ (i + 1) * cnt - val�� ������Ѵ�.
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

// ������ ���ŵǴ� ���׸�Ʈ Ʈ��
void lazyprop(int start, int end, int node)
{
	if (segmenttree[node].cnt == 0)
		return;

	long long val = segmenttree[node].val;
	long long cnt = segmenttree[node].cnt;

	if (start != end)
	{
		// ������ ����
		segmenttree[node * 2].val += val;
		segmenttree[node * 2].cnt += cnt;
		segmenttree[node * 2 + 1].val += val;
		segmenttree[node * 2 + 1].cnt += cnt;
	}

	if (start == end)
		arr[start] += (start + 1) * cnt - val;

	// �� �ʱ�ȭ
	segmenttree[node].val = 0;
	segmenttree[node].cnt = 0;
}

void updatetree(int start, int end, int node, int left, int right)
{
	// ������ ó���ؾ��� �۾��� �ֳ� Ȯ��
	lazyprop(start, end, node);

	// ������ ���� x��� pass
	if (start > right || end < left)
		return;

	// ������ ���Ѵٸ� ó��
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
	// ������ ó���ؾ��� �۾��� �ֳ� Ȯ��
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