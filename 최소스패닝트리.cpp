#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	int s, e, dis;
	// ������, ����, ����ġ
};

bool cmp(node a, node b)
{
	return a.dis < b.dis;
}

int v, e, root[10001], cnt[10001], ans;
// ����, ����, �θ� ���, �׷����� ���� ����� ����
node path[100000];

void input()
{
	cin >> v >> e;

	for (int i = 0; i < e; i++)
		cin >> path[i].s >> path[i].e >> path[i].dis;
}

int find(int n)
{
	if (root[n] == n)
		return n;

	return root[n] = find(root[n]);
}

void solution()
{
	sort(path, path + e, cmp);

	for (int i = 1; i <= v; i++)         // union_find�� ���� �ʱ�ȭ
	{
		root[i] = i;
		cnt[i] = 1;
	}

	for (int i = 0; i < e; i++)
	{
		if (cnt[1] == v)                // ��� ������ ����ƴٸ� Ż��
			break;

		int sroot = find(path[i].s);    // �������� �θ���
		int eroot = find(path[i].e);    // ������ �θ���

		if (sroot == eroot)             // �̹� ���� �׷����� �����ִٸ� ������ �ʿ� x
			continue;

		ans += path[i].dis;

		// �� ���� ������ �θ���� ���� �� ��� ���� ������
		if (sroot < eroot)
		{
			root[eroot] = sroot;
			cnt[sroot] += cnt[eroot];
		}

		else
		{
			root[sroot] = eroot;
			cnt[eroot] += cnt[sroot];
		}
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