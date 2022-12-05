#include <iostream>
#include <vector>
#define N 500001

using namespace std;

int n, m, idx;
long long pay[N], realpay[N], tree[4 * N], lazy[4 * N];
// ������ ���۰� �� ����
int s[N], e[N];
vector<int> sub[N];

void input()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int boss;

		if (i == 1)
		{
			cin >> pay[i];
			continue;
		}

		cin >> pay[i] >> boss;
		sub[boss].push_back(i);
	}
}

// ���Ϸ� ��� ��ũ���� Ȱ���� �ε����� ���׸�Ʈ Ʈ�� ���� �Է�
void Euler(int node)
{
	s[node] = ++idx;

	for (int i = 0; i < sub[node].size(); i++)
		Euler(sub[node][i]);

	e[node] = idx;
}

// ���س��� �ε����� ������ ���� ���׸�Ʈ Ʈ�� ����
void settree(int start, int end, int node)
{
	if (start == end)
	{
		tree[node] = realpay[start];
		return;
	}

	int mid = (start + end) / 2;

	settree(start, mid, node * 2);
	settree(mid + 1, end, node * 2 + 1);
}

void lazycheck(int start, int end, int node)
{
	if (!lazy[node])
		return;

	tree[node] += lazy[node];

	if (start != end)
	{
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}

	lazy[node] = 0;
}

void update(int start, int end, int left, int right, long long val, int node)
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

	update(start, mid, left, right, val, node * 2);
	update(mid + 1, end, left, right, val, node * 2 + 1);
}

long long output(int start, int end, int idx, int node)
{
	lazycheck(start, end, node);

	if (end < idx || start > idx)
		return 0;

	if (start == idx && start == end)
		return tree[node];

	int mid = (start + end) / 2;

	return output(start, mid, idx, node * 2) + output(mid + 1, end, idx, node * 2 + 1);
}

void solution()
{
	Euler(1);

	// �갡 ���� AC -> why?????
	// ex. s[5] = 6�� �� (���׸�Ʈ Ʈ�������� 5�� index�� 6), realpay[s[5]] = pay[5]
	// realpay[6] = 5 (���׸�Ʈ Ʈ������ index 6�� ���� 5)
	// pay[s[5]] = pay[6] = 6 (�߸��� �� ��� Ȯ��)
	for (int i = 1; i <= n; i++)
		realpay[s[i]] = pay[i];

	settree(1, n, 1);

	while (m--)
	{
		char c;
		int a;
		long long x;
		cin >> c;

		if (c == 'p')
		{
			cin >> a >> x;

			if (s[a] < e[a])
				update(1, n, s[a] + 1, e[a], x, 1);
		}

		else
		{
			cin >> a;
			cout << output(1, n, s[a], 1) << '\n';
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