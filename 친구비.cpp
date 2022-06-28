// �ּ� ���д� Ʈ���� �����ϰ� Ǭ Ǯ��
#include <iostream>
#include <algorithm>
#define p pair<int, int>

using namespace std;

int n, m, k, root[10001], check[10001], ans;
// �ؼ�'s index == 0

p cost[10001];
// cost, index

void setroot()
{
	for (int i = 1; i <= n; i++)
		root[i] = i;
}

int find(int node)
{
	if (root[node] == node)
		return node;

	return root[node] = find(root[node]);
}

void input()
{
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		int c;
		cin >> c;

		cost[i].first = c;
		cost[i].second = i;
	}

	setroot();

	while (m--)
	{
		int a, b;
		cin >> a >> b;

		int aroot = find(a);
		int broot = find(b);

		if (aroot == broot)
			continue;

		// index�� �� ���� ��带 ��Ʈ ���� ����
		if (aroot < broot)
			root[broot] = aroot;

		else
			root[aroot] = broot;
	}
}

void solution()
{
	sort(cost + 1, cost + n + 1);

	int idx = 1;

	while (idx <= n)
	{
		int price = cost[idx].first;
		int curidx = cost[idx].second;
		int curidxroot = find(curidx);

		// �̹� ģ����� pass
		if (check[curidxroot])
		{
			idx++;
			continue;
		}

		ans += price;
		k -= price;
		check[curidxroot] = 1;

		if (k < 0)
		{
			ans = -1;
			break;
		}

		idx++;
	}

	ans == -1 ? cout << "Oh no" : cout << ans;
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

// ���� �� ������ �������� Ǯ��
/*
#include <iostream>

using namespace std;

int n, m, k, root[10001], cost[10001], ans;

void setroot()
{
	for (int i = 1; i <= n; i++)
		root[i] = i;
}

int find(int node)
{
	if (root[node] == node)
		return node;

	return root[node] = find(root[node]);
}

void input()
{
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> cost[i];

	setroot();

	while (m--)
	{
		int a, b;
		cin >> a >> b;

		int aroot = find(a);
		int broot = find(b);

		if (aroot == broot)
			continue;

		// cost�� �� ���� ��带 ��Ʈ ���� ����
		if (cost[aroot] < cost[broot])
			root[broot] = aroot;

		else
			root[aroot] = broot;
	}
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		if (root[i] == i)
		{
			ans += cost[i];
			k -= cost[i];
		}

		if (k < 0)
		{
			ans = -1;
			break;
		}
	}

	ans == -1 ? cout << "Oh no" : cout << ans;
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
*/